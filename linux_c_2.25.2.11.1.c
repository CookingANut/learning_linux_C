#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define stringCache 20


static char current_time_str[stringCache];

void get_current_time()
/*
 *  get current time and format it to string
 */
{
    if (sizeof(current_time_str) < 8) {
        printf("cur string lenth is < 20\n");
        exit(1);
    }

    time_t *CURRENTTIME = NULL;
    time_t cur_time;
    cur_time = time(NULL);
    CURRENTTIME = &cur_time;
    struct tm *LOCALTIME = localtime(CURRENTTIME);

    sprintf(current_time_str, "%d-%d-%d %d:%d:%d\n",
            LOCALTIME->tm_year + 1900,
            LOCALTIME->tm_mon,
            LOCALTIME->tm_mday,
            LOCALTIME->tm_hour,
            LOCALTIME->tm_min,
            LOCALTIME->tm_sec);
}

int main()
{
    FILE * RECORD;

    do {
        if ( (RECORD = fopen("RECORD.log", "a+")) == NULL) { 
            perror("Error occur, open source file"); 
            exit(1); 
        }
        
        fseek(RECORD, 0, SEEK_END);
        get_current_time();
        printf("%s", current_time_str);
        fputs(current_time_str, RECORD);
        sleep(1);
        fclose(RECORD);
    } while ( 1);

    return 0;
}