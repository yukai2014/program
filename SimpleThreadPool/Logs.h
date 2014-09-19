/*
 * logs.h
 *
 *  Created on: 2014-9-2
 *      Author: imdb
 */

#ifndef LOGS_H_
#define LOGS_H_

#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>


#define OUTPUTERROR(a) cout<<"ERROR:"<<strerror(errno)<<"."<<a<<endl

#define DEBUG

class Logs
{
public:
	static void log(const char *format, ...){
	#ifdef DEBUG
		va_list arg;
		va_start(arg, format);
		vprintf(format, arg);
		printf("\n");
		va_end(arg);
	#endif
	}
};


#endif /* LOGS_H_ */
