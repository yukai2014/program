/*
 * Log.h
 *
 *  Created on: 2014-10-27
 *      Author: YuKai
 */

#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>
#include <sys/time.h>

#define INFO
#define DEBUG

/*
 * TODO: change Define to function in order to decrease code size
 * take multi-thread into account in case of a sentence being split into multiple lines
 */

#define LOGINFO(type) \
struct timeval tv; \
struct tm *tm; \
gettimeofday(&tv, NULL); \
tm = localtime(&tv.tv_sec); \
printf("[%d-%d-%d %d:%d:%d.%ld]  ", \
tm->tm_year+1900, tm->tm_mon, tm->tm_mday, \
tm->tm_hour, tm->tm_min, tm->tm_sec, \
tv.tv_usec); \
printf(type); \
printf("  %s:%d	", \
__FILE__, __LINE__);

#ifdef INFO
#define LOG(format, ...) \
{ \
	LOGINFO("INFO ") \
	printf(format, ##__VA_ARGS__); \
	printf("\n"); \
}
#define LOGS(s) \
{ \
	LOGINFO("INFO ") \
	cout<<s<<endl; \
}
#else
#define LOG(format, ...)
#define LOGS(format, ...)
#endif


#ifdef DEBUG
#define DLOG(format, ...) \
{ \
	LOGINFO("DEBUG") \
	printf(format, ##__VA_ARGS__); \
	printf("\n"); \
}

#define DLOGS(s) \
{ \
	LOGINFO("DEBUG") \
	cout<<s<<endl; \
}
#else
#define DLOG(format, ...)
#define DLOGS(format, ...)
#endif


#define ELOG(format, ...) \
{ \
	LOGINFO("ERROR") \
	printf(format, ##__VA_ARGS__); \
	printf("\n"); \
}

#define ELOGS(s) \
{ \
	LOGINFO("ERROR") \
	cout<<s<<endl; \
}

#endif /* LOG_H_ */
