/*
 * SocketClient.cpp
 *
 *  Created on: 2014-8-28
 *      Author: imdb
 */

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
using namespace std;

const int BUF_MAX = 1024;

int main()
{
	sockaddr_in server_addr;
	int client_socket;
	char buf[BUF_MAX];

	if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		cout<<"error, create socket failed"<<endl;
		return 0;
	}

	bzero(&server_addr, sizeof(server_addr));
//	server_addr.sin_addr.s_addr = inet_addr("58.198.176.153");
	server_addr.sin_addr.s_addr = inet_addr("10.11.1.90");
	server_addr.sin_family = AF_INET;
#ifdef EPOLL
	server_addr.sin_port = htons(34568);
	cout<<"set port ok"<<endl;
#endif

#ifdef SOCKET
	server_addr.sin_port = htons(34567);
#endif

	if (connect(client_socket, (sockaddr *)&server_addr, sizeof(server_addr)) < 0){
		cout<<"error: "<<strerror(errno)<<". connect failed. "<<endl;
		return 0;
	}

/*
	memset(buf, 0, sizeof(buf));
	memcpy(buf, "hello, world1", 13);
	cout<<send(client_socket, buf, strlen(buf), 0)<<endl;
	buf[12] = '2';
	write(client_socket, buf, strlen(buf));
	buf[12] = '3';
	write(client_socket, buf, strlen(buf));
*/

	memset(buf, 0, sizeof(buf));
	cin.getline(buf, BUF_MAX-1);
	if (send(client_socket, buf, strlen(buf)+1, 0) <= 0){
		cout<<"error"<<errno<<": write to server failed. "<<endl;
		return 0;
	}

	//read message from server
	int read_count = 0;
	if ((read_count = read(client_socket, buf, BUF_MAX)) < 0){
		cout<<"error"<<errno<<": read from server failed. "<<endl;
		return 0;
	}
	else if (read_count == 0) {
		cout<<"error"<<errno<<": read nothing ."<<endl;
		return 0;
	} else {
		cout<<"receive "<<read_count<<" char from server:"<<buf<<endl;
	}

	if (close (client_socket) == -1)
		cout<<"ERROR:"<<strerror(errno)<<endl;

	return 0;
}
