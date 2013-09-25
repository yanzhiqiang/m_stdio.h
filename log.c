#include "log.h"


LOG_LEVEL log_level=LOG_INFO;
char file_name[20]="log_log";
int MAX_FILE_SIZE=8*1024*1024;

int set_log_filename(const char* t_file_name)
{
	if(file_name)
	{
		if(strlen(t_file_name) < 20 )
		{
			memcpy(file_name,t_file_name,strlen(t_file_name));
		}
	}
}

int set_log_level(const LOG_LEVEL t_log_level)
{	
	log_level=t_log_level;
}

int log_to_file(const LOG_LEVEL log_level,const char* format, ...)
{
	if(!fp_name)
		return -1;
	FILE* fp = NULL;
	fp = fopen(fp_name,"wb+");
	

}