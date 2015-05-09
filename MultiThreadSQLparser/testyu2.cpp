//============================================================================
// Name        : testyu2.cpp
// Author      : Yu Kai
// Version     :
// Copyright   : kkl
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <pthread.h>
using namespace std;
#include "sql_node_struct.h"

extern "C" int yylex();
extern "C" int yyparse();
extern char globalInputText[10000];
extern int numToRead;

pthread_mutex_t mutex;		//互斥锁
struct timespec delay;		//延时量

void * runStl(void* arg)
{
	cout<<"this is a pthread"<<endl;
//	int charnum=0;
//	while(1)
//	{
//		char c=getchar();
//		globalInputText[charnum++]=c;
//		if(c==';')
//		{
//			globalInputText[charnum++]='\0';
//			break;
//		}
//	}


	char * a = (char*)arg;
	puts("locked");
	pthread_mutex_lock(&mutex);
	memset(globalInputText, 0, sizeof(globalInputText));
	strcpy(globalInputText, a);
	puts(globalInputText);

					numToRead = strlen(globalInputText);

					if(!yyparse())
					{
						printf("SQL parse worked\n");
					}
					else
					{
						printf("SQL parse failed\n");
					}
}

int main() {
	puts("!!!Hello World!!!"); // prints !!!Hello World!!!
	pthread_t id1,id2,id3;
	delay.tv_sec = 0;
	delay.tv_nsec = 500;
	pthread_mutex_init(&mutex, NULL);
	int i, ret;

	char* sql_stmt1 = "select a from b;";
	char* sql_stmt2 = "select a from c;";
	char* sql_stmt3 = "select a from d;";
	char* sql_stmt4 = "select a from e;";
	ret = pthread_create(&id1, NULL, runStl, sql_stmt2);
	if (ret != 0)
	{
		cout<<"Create pthread failed!"<<endl;
		exit(1);
	}
	ret = pthread_create(&id2, NULL, runStl, sql_stmt3);
	if (ret != 0)
	{
		cout<<"Create pthread failed!"<<endl;
		exit(1);
	}
	ret = pthread_create(&id3, NULL, runStl, sql_stmt4);
	if (ret != 0)
	{
		cout<<"Create pthread failed!"<<endl;
		exit(1);
	}
	puts("this is the main process");

	//pthread_delay_np(&delay);

	runStl(sql_stmt1);
	puts("this is the main process");
//	runStl(sql_stmt2);
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	pthread_join(id3, NULL);
	puts("this is all");
	return 0;
}

//
//int main()
//{
//	char c;
//		while(1)
//		{
//			int charnum=0;
//		    	while(1)
//		    	{
//				char c=getchar();
//				globalInputText[charnum++] = c;
//				if(c==';')
//				{
//				    globalInputText[charnum++]='\0';
//				    break;
//				}
//		  	}
//		    	puts(globalInputText);
//
//			numToRead = strlen(globalInputText);
//
//			if(!yyparse())
//			{
//				printf("SQL parse worked\n");
//			}
//			else
//			{
//				printf("SQL parse failed\n");
//			}
//			c = getchar();
//			while(c != '\n')
//			{
//				c = getchar();
//			}
//			cout<<"q for quit, other for continue"<<endl;
//			c = getchar();
//			cout<<c<<endl;
//			if(c == 'q') break;
//		}
//	return 0;
//}
