/*******************************************************************************
Filename: pmod.c
Name: Christopher Myers
Assignment: Lab 9
Date: 11/12/2024
Course: CPE 2600-121
*******************************************************************************/

#include <sys/resource.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    // Reduce task piority
    nice(getpriority(PRIO_PROCESS, 0) + 10);
    // Sleep for 1,837,272,638 nanoseconds
    struct timespec ts = {.tv_sec = 1, .tv_nsec = 837272638};
    nanosleep(&ts, NULL);
    printf("Goodbye\n");

    return 0;
}