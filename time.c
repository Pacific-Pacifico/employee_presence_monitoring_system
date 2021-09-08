#include<stdio.h>
#include<time.h>
#include"globals.h"

unsigned long get_timestamp()
{
    return (unsigned long)time(NULL);
}

char *convert_timestamp_to_time(unsigned long timestamp)
{
    // int hour,minute,second,
    int day,month,year;
    static char buf[30];
    time_t now;
    time(&now);
    struct tm *local=localtime(&now);

    // hour = local->tm_hour;         // get hours since midnight (0-23)
    // minute = local->tm_min;        // get minutes passed after the hour (0-59)
    // second = local->tm_sec;        // get seconds passed after a minute (0-59)
    day = local->tm_mday;            // get day of month (1 to 31)
    month = local->tm_mon + 1;      // get month of year (0 to 11)
    year = local->tm_year + 1900;   // get year since 1900

    // print the current date
    // printf("Date is: %02d/%02d/%d\n", day, month, year);
    // printf("Time is: %02d-%02d-%d\n", hour, minute, second);
    sprintf(buf,"%d-%d-%d",day,month,year);
    return buf;
}