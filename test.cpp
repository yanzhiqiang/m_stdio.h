#include "m_stdio.h"
int main(int argv,char** argc)
{
	//test log 
	int i=0;
	set_log_filename("a");
	set_log_level(FLOG_NORMAL);
	while (1)
	{
		i++;
		
		//log_to_file(3,"i am here %d");
		log_to_file(FLOG_NORMAL,"i am here %d",i);
	}
	return 0;
}
