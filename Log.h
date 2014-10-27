/*
 * Log.h
 *
 *  Created on: 2014-10-27
 *      Author: imdb
 */

#ifndef LOG_H_
#define LOG_H_

#include <sys/time.h>

#define DEBUG

#define LOGINFO \
struct timeval tv; \
struct tm *tm; \
gettimeofday(&tv, NULL); \
tm = localtime(&tv.tv_sec); \
printf("[%d-%d-%d %d:%d:%d.%ld]	INFO	%s:%d	", \
tm->tm_year+1900, tm->tm_mon, tm->tm_mday, \
tm->tm_hour, tm->tm_min, tm->tm_sec, \
tv.tv_usec, \
__FILE__, __LINE__);

#ifdef DEBUG
#define LOG(format, ...) \
{ \
	LOGINFO \
	printf(format, ##__VA_ARGS__); \
	printf("\n"); \
}

#define LOGS(s) \
{ \
	LOGINFO \
	cout<<s<<endl; \
}
#endif

#define ELOG(format, ...) \
{ \
	LOGINFO \
	printf(format, ##__VA_ARGS__); \
	printf("\n"); \
}

#define ELOGS(s) \
{ \
	LOGINFO \
	cout<<s<<endl; \
}

#endif /* LOG_H_ */
