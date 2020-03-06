/* 不是很懂... */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

static FILE* logfile = NULL;

int printlog(const char*fmt, ...);

int main() {
    
}

int printlog(const char*fmt, ...) {
    va_list args;
    if (NULL == logfile) {
        logfile = fopen("the_log", "a");
        if (NULL == logfile) return -1;
    }
    va_start(args, fmt);
    return vfprintf(logfile, fmt, args);
}