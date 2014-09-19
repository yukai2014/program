/*
 * EpollServer.cpp
 *
 *  Created on: 2014-8-28
 *      Author: imdb
 */

#include <iostream>
#include <errno.h>
#include <sys/epoll.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <map>
#include <unistd.h>
#include "Logs.h"
using namespace std;

const int CONNECTION_MAX = 10;
const int MESSAGE_LENGTH_MAX = 1024;
const int TIME_OUT = 1000;

map<int , sockaddr_in> fd_to_adddr;

// accept connection and push new socket into epoll list
bool AcceptConnection(int epoll_fd, int fd)
{
	Logs::log("in AcceptConnection function");
	sockaddr_in connected_socket;
	bzero(&connected_socket, sizeof(connected_socket));

	socklen_t length = sizeof(connected_socket);
	int connected_fd = accept(fd, (sockaddr*)&connected_socket, &length);
	if (connected_fd < 0){
		OUTPUTERROR(" accept socket failed.");
		return false;
	}
	else{
		Logs::log("fd is %d",connected_fd);
		printf("accept socket connection from %s:%d\n", inet_ntoa(connected_socket.sin_addr), ntohs(connected_socket.sin_port));
		fd_to_adddr.insert(pair<int, sockaddr_in>(connected_fd, connected_socket));
	}

	// register new socket to epoll
	epoll_event event;
	event.events = EPOLLIN|EPOLLET;

	//make sure this fd equal with connected socket fd returned from accept()
	event.data.fd = connected_fd;
	epoll_ctl(epoll_fd, EPOLL_CTL_ADD, connected_fd, &event);

	return true;
}

// receive data from client socket
bool ReceiveData(epoll_event event, char *buf)
{
	Logs::log("in ReceiveData function");
	memset(buf, 0, sizeof(buf));
	int recv_count = recv(event.data.fd, buf, MESSAGE_LENGTH_MAX, 0);
	if (recv_count < 0){
		OUTPUTERROR(" read data failed.");
		return false;
	}
	else if (recv_count == 0){	// client exit normally will make epoll readable but can read nothing	-9.17
		printf("received nothing . Client close normally\n");
		epoll_ctl(epoll_fd, EPOLL_CTL_DEL, event.data.fd, NULL);
		return false;
	}

	sockaddr_in client_addr = fd_to_adddr.at(event.data.fd);
	Logs::log("receive content:%s\n		------from %s:%d\n", buf, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
	return true;
}

bool SendMessageBack(int client_fd)
{
	char buf[] = "ok, server have received successfully\n";
	int write_count = send(client_fd, buf, strlen(buf), 0);
	if (write_count <= 0){
		OUTPUTERROR(" write to client socket failed.");
		return false;
	}
	Logs::log("ok, write to client socket successfully\n");
	return true;
}

void CloseAllConnection()
{
	map<int, sockaddr_in>::iterator it;
	for (it = fd_to_adddr.begin(); it != fd_to_adddr.end(); ++it){
		if (it->first != 0){
			close(it->first);
		}
	}
}

int main()
{
	epoll_event event_list[CONNECTION_MAX];
	sockaddr_in addr;
	int listen_fd;
	int epoll_fd;
	int ret;
	char buf[MESSAGE_LENGTH_MAX+1];
	memset(buf, 0, sizeof(buf));

	if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		OUTPUTERROR(" create socket failed. ");
		return 0;
	}
	// enable address reuse
	int temp_val = 1;
	setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &temp_val, sizeof(temp_val));

	bzero(&addr, sizeof(addr));
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(34568);

	if (bind(listen_fd, (sockaddr*)&addr, sizeof(addr)) == -1){
		OUTPUTERROR(" bind socket failed. ");
		close(listen_fd);
		return 0;
	}

//	fd_to_adddr.insert(pair<int, sockaddr_in>(listen_fd, addr));

	listen(listen_fd, CONNECTION_MAX);

	if ((epoll_fd = epoll_create(CONNECTION_MAX)) == -1){
		OUTPUTERROR(" create epoll failed. ");
		close(listen_fd);
		return 0;
	}

	// EPOLLIN： 触发该事件，表示对应的文件描述符上有可读数据。(包括对端SOCKET正常关闭)；
	epoll_event event;
	event.events = EPOLLIN|EPOLLET;
	event.data.fd = listen_fd;
	if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_fd, &event)){
		OUTPUTERROR(" register epoll failed. ");
		close(listen_fd);
		close(epoll_fd);
		return 0;
	}

	while(1){
		if ((ret = epoll_wait(epoll_fd, event_list, CONNECTION_MAX, TIME_OUT)) == -1){
			OUTPUTERROR(" wait epoll failed. ");
			break;
		}
		else if (ret == 0){
//			Logs::log("time out, keep waiting...");
		}
		else{
//			cout<<"ret is "<<ret<<endl;
			for(int i = 0; i < ret; ++i)
			{
/*
				// accept return a new socket which is connected with client!!!!!!!!!!
				accept(event_list[i].data.fd, (sockaddr *)&client_addr, &length);
				// so recv should receive from new socket which accept return!!!!!!!!!
				if (recv(event_list[i].data.fd, buf, MESSAGE_LENGTH_MAX, 0) == -1){
					cout<<"error:"<<strerror(errno)<<". receive data failed. "<<endl;
					close(epoll_fd);
					close(listen_fd);
					return 0;
				}
*/
				// exit abnormally
				if ((event_list[i].events & EPOLLERR) || (event_list[i].events & EPOLLHUP) || !(event_list[i].events & EPOLLIN))
				{
					sockaddr_in temp = fd_to_adddr.at(event_list[i].data.fd);
					printf("%s.%d exit abnormally.\n",inet_ntoa(temp.sin_addr), ntohs(temp.sin_port));
					close(event_list[i].data.fd);
					epoll_ctl(epoll_fd, EPOLL_CTL_DEL, event_list[i].data.fd, NULL);	// unregister this fd
					continue;
				}

				Logs::log("listen fd is:	%d", listen_fd);
				Logs::log("available fd is:	%d", event_list[i].data.fd);
				if (event_list[i].data.fd == listen_fd){
					AcceptConnection(epoll_fd, listen_fd);
				}
				else{
					if (ReceiveData(event_list[i], buf) == true){
						SendMessageBack(event_list[i].data.fd);
//						sleep(1);
//						SendMessageBack(event_list[i].data.fd);
					}
				}
			}
		}//end else
	}

	CloseAllConnection();
	close(epoll_fd);
	close(listen_fd);

	return 0;
}
