/*******************************************************************************
Filename: info.c
Name: Christopher Myers
Assignment: Lab 9
Date: 11/12/2024
Course: CPE 2600-121
*******************************************************************************/

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>

int main(int argc, char* argv[]) {

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    
    printf("Time of day in nanoseconds: %ld\n", (long)(tm.tm_hour * 60 * 60 * 10E9 + tm.tm_min * 60 * 10E9 + tm.tm_sec * 10E9) + ts.tv_nsec);

    struct utsname sysinfo;
    uname(&sysinfo);
    printf("Current Network: %s\n", sysinfo.nodename);
    printf("System Name: %s\n", sysinfo.sysname);
    printf("Release: %s\n", sysinfo.release);
    printf("Version: %s\n", sysinfo.version);
    printf("Hardware Type: %s\n", sysinfo.machine);
    
    // Can also be used to get network name
    /*
    char hostname[256];
    gethostname(hostname, sizeof(hostname));
    printf("The Network Name is: %s\n", hostname);
    */

    printf("Number of Logical Processors: %d\n", get_nprocs());

    printf("Physical Memory Size: %ld\n", sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGE_SIZE));
    printf("Page Size: %d\n", getpagesize());

    return 0;
}