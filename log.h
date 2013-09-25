#ifndef __LOG_H_
#define __LOG_H_

typedef enum
{
	LOG_DEBUG = 1,
	LOG_WARNNING = 2,
	LOG_INFO  = 3,
	LOG_ERROR = 4
}LOG_LEVEL;



int set_log_filename(const char* file_name);
int set_log_level(const LOG_LEVEL log_level);
int log_to_file(const LOG_LEVEL log_level,const char* format, ...);

#endif
