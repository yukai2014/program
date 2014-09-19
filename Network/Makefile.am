bin_PROGRAMS = epserver sserver epclient sclient

epserver_SOURCES = 		EpollServer.cpp \
	Logs.h 				
	
epserver_CPPFLAGS=-fPIC
	
epserver_LDFLAGS = -g

#######################


sserver_SOURCES = 	SocketServer.cpp

sserver_CPPFLAGS=-fPIC
	
sserver_LDFLAGS = -fPIC -g

#######################


epclient_SOURCES = 	SocketClient.cpp
	
epclient_CPPFLAGS=-fPIC
	
epclient_LDFLAGS = -fPIC -D SOCKET -g

#######################


sclient_CPPFLAGS=-fPIC

sclient_SOURCES = 	SocketClient.cpp
	
sclient_LDFLAGS = -D EPOLL -g