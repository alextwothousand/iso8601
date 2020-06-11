#pragma once

#include <stdio.h>
#include <time.h>

int iso8601(char* string) {
    time_t rawtime = time(NULL);

    if (rawtime == -1) {
        return 0;
    }
    
    struct tm *ptm = localtime(&rawtime);

    if (ptm == NULL) {
        return 0;
    }
    
    sprintf(string, "%04d-%02d-%02dT%02d:%02d:%02d.000Z", (ptm->tm_year + 1900), (ptm->tm_mon + 1), ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
    return 1;
}
