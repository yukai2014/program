bin_PROGRAMS = epserver sserver epclient sclient

epserver_SOURCES = 		EpollServer.cpp \
	Logs.h 				
	
epserver_CPPFLAGS= -g -fPIC
	
#epserver_LDFLAGS =

#######################


sserver_SOURCES = 	SocketServer.cpp

sserver_CPPFLAGS=-g -fPIC
	
#sserver_LDFLAGS =  

#######################


epclient_SOURCES = 	SocketClient.cpp
	
epclient_CPPFLAGS=-g -DEPOLL -fPIC
	
#epclient_LDFLAGS =  

#######################


sclient_SOURCES = 	SocketClient.cpp

sclient_CPPFLAGS= -g -DSOCKET -fPIC
	
#sclient_LDFLAGS = 