/*
 * SocketServer.cpp
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

using namespace std;

const int CONNECTION_MAX = 10;

const int BUF_MAX = 1024;

int main()
{
	int listen_socket, connected_socket;
	sockaddr_in addr, connected_addr;
	char buf[BUF_MAX];
	memset(buf, 0, sizeof(buf));

	if((listen_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		cout<<"error, create socket failed"<<endl;
		return 0;
	}

	bzero(&addr, sizeof(addr));
	addr.sin_port = htons(34567);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_family = AF_INET;

	if (bind(listen_socket, (struct sockaddr *)&addr, sizeof(addr)) == -1){
		cout<<"error, bind socket failed"<<endl;
		return 0;
	}
	listen(listen_socket, CONNECTION_MAX);

	socklen_t length = sizeof(connected_addr);
	connected_socket = accept(listen_socket, (sockaddr *)&connected_addr, &length);

	if (connected_socket == -1){
		cout<<"error, accept socket connection failed"<<endl;
		return 0;
	}

	int rev_num = recv(connected_socket, buf, BUF_MAX, 0);
	if (rev_num > 0){
		cout<<"receive "<<rev_num<<" bytes from "<<inet_ntoa(connected_addr.sin_addr)<<":"<<ntohs(connected_addr.sin_port)<<endl;
//		buf[rev_num] = '\0';
		cout<<buf<<endl;
	}

	return 0;
}
