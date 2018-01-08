#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define max 500
#include "email.h"

void updatetime(sentbox* temp)
{
	time_t rawtime;
	struct tm * timeinfo;
	int day,month,year,hour,min,sec;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	day = timeinfo->tm_mday; month = timeinfo->tm_mon; year = timeinfo->tm_year;
	hour = timeinfo->tm_hour; min = timeinfo->tm_min; sec = timeinfo->tm_sec;
	//t1->day=day;
	//t1->month=month+1;
	//t1->year=year+1990;
	temp->data.hr=hour;
	temp->data.min=min;
	temp->data.sec=sec;
	
}

