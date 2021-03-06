#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"globals.h"

unsigned long get_timestamp()
{
    return (unsigned long)time(NULL);
}

struct Time *convert_timestamp_to_time(unsigned long timestamp)
{
    // int hour,minute,second,
    // int day,month,year;
    struct Time *t;
    t=(struct Time *)malloc(sizeof(struct Time));
    time_t now;
    time(&now);
    struct tm *local=localtime(&now);
    t->hour = local->tm_hour;         // get hours since midnight (0-23)
    t->minute = local->tm_min;        // get minutes passed after the hour (0-59)
    t->second = local->tm_sec;        // get seconds passed after a minute (0-59)
    // day = local->tm_mday;            // get day of month (1 to 31)
    // month = local->tm_mon + 1;      // get month of year (0 to 11)
    // year = local->tm_year + 1900;   // get year since 1900

    // print the current date
    // printf("Date is: %02d/%02d/%d\n", day, month, year);
    // printf("Time is: %02d-%02d-%d\n", hour, minute, second);   
    t->next=NULL;
    return t;
}

struct Time *insert_beg(struct Time *start,struct Time *temp)
{
    start=temp;
    return start;
}

struct Time *insert_end(struct Time *start,struct Time *temp)
{
    struct Time *p=start;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=temp;
    return start;
}

void show_out_times(struct Time *start)
{
    struct Time *p=start;
    if(start==NULL)
    {
        printf("\nEmpty list");
        return;
    }
    while(p!=NULL)
    {
        printf("\nhour=%hu ,min=%hu,sec=%hu",p->hour,p->minute,p->second);
        p=p->next;
    }
}