#include <time.h>
#include <stdio.h>
#include <string.h>

void sprint_time(char* outstr, struct tm* info)
{
   sprintf(outstr, "Current time is: %02d:%02d:%02d\n", info->tm_hour, info->tm_min, info->tm_sec);
}

void sprint_date(char* outstr, struct tm* info)
{
    char* days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    sprintf(outstr, "Today is: %s, %02d:%02d:%04d\n", days[info->tm_wday], info->tm_mday, info->tm_mon+1, info->tm_year+1900);
}

int main()
{
    time_t current_time = time(NULL);
    //the struct tm is in the time.h library
    struct tm* info = localtime(&current_time);
    // info->
    // // print current time
    // info->tm_hour; // hour
    // info->tm_min; // minute
    // info->tm_sec; // second

    // // print current date
    // info->tm_mday; // day
    // info->tm_mon + 1; // month
    // info->tm_year + 1900; // year

    // info->tm_wday; // day of the week: 0 -> Sun, 1 -> Mon, ...
    char outstring[10000];//buffer
    char outstring2[10000];
    sprint_time(outstring, info);
    sprint_date(outstring2, info);
    printf("%s", outstring);
    printf("%s", outstring2);
    return 0;
}