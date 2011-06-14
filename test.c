#include <stdio.h>
#include <time.h>
#include <libnotify/notify.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    time_t rawtime;
    struct tm *timeinfo;

    time (&rawtime);
    timeinfo = localtime(&rawtime);
    mktime(timeinfo);

    printf ("That min is a %i.\n", timeinfo->tm_min);

    char buffer[10];
    int i = 20;
    snprintf(buffer, 10,"%d",timeinfo->tm_min);

    NotifyNotification *n;  
    notify_init("Test");  
    n = notify_notification_new ("15 min passed", buffer, NULL, NULL);  
    notify_notification_set_timeout(n, 1000); // 1 second  
    if (!notify_notification_show (n, NULL)) {  
        g_error("Failed to send notification.\n");  
        return 1;  
    }  
    g_object_unref(G_OBJECT(n));  

    return 0;
}
