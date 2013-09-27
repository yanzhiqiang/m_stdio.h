#include "m_stdio.h"
#include <stdio.h>

void test_log();
void test_time();

int main(int argv,char** argc)
{
	test_log();
	//test_time();
	return 0;
}

void test_time()
{
	printf("%s,%lld",GetDateTime(),GetCountTick());
}

void test_log()
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
}
