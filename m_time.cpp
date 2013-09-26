#include "m_time.h"
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

long long GetCountTick()
{
	struct timeval t_timeval;
	struct timezone t_tz;
	gettimeofday(&t_timeval,&t_tz);
	long long t_ms = 0;
	t_ms = t_timeval.tv_sec*1000+t_timeval.tv_usec/1000;
	return t_ms;
}

char*	GetDateTime()
{
	time_t timep;
	time(&timep);
	return ctime(&timep);

}
