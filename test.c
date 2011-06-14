/* mktime example: weekday calculator */
#include <stdio.h>
#include <time.h>
#include <libnotify/notify.h>
#include <stdlib.h>

int main ()
{
    time_t rawtime;
    struct tm *timeinfo;
    int year, month ,day;
    char *weekday[] = { "Sunday", "Monday",
        "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"};

    /* prompt user for date */
    //printf ("Enter year: "); scanf ("%d",&year);
    //printf ("Enter month: "); scanf ("%d",&month);
    //printf ("Enter day: "); scanf ("%d",&day);

    /* get current timeinfo and modify it to the user's choice */
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    //timeinfo->tm_year = year - 1900;
    //timeinfo->tm_mon = month - 1;
    //timeinfo->tm_mday = day;

    /* call mktime: timeinfo->tm_wday will be set */
    mktime (timeinfo);

    printf ("That day is a %s.\n", weekday[timeinfo->tm_wday]);
    printf ("That min is a %i.\n", timeinfo->tm_min);


    char buffer[10];
    int i = 20;
    snprintf(buffer, 10,"%d",timeinfo->tm_min);

    NotifyNotification *n;  
    notify_init("Test");  
    n = notify_notification_new ("15 min passed", buffer, NULL, NULL);  
    notify_notification_set_timeout(n, 1000); //3 seconds  
    if (!notify_notification_show (n, NULL)) {  
        g_error("Failed to send notification.\n");  
        return 1;  
    }  
    g_object_unref(G_OBJECT(n));  

    return 0;
}
