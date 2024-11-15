/*******************************************************************************
Filename: pinfo.c
Name: Christopher Myers
Assignment: Lab 9
Date: 11/12/2024
Course: CPE 2600-121
*******************************************************************************/

#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <sys/resource.h>
#include <errno.h>
#include <signal.h>
//#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int pid;
    if(argc == 1) { // If no argument check for this process
        pid = 0;
    } else { // Parse the pid argument
        pid = strtol(argv[1], NULL, 10);
    }

    if(kill(pid, 0) == -1 && errno == ESRCH) {
        printf("The process does not exist.\n");
    } else {
        // Print priority and scheduling policy
        printf("Process Priority: %d\n", getpriority(PRIO_PROCESS, pid));
        switch(sched_getscheduler(pid)) {
            case SCHED_OTHER:
                printf("Policy: SCHED_OTHER\n");
                break;
            case SCHED_BATCH:
                printf("Policy: SCHED_BATCH\n");
                break;
            case SCHED_IDLE:
                printf("Policy: SCHED_IDLE\n");
                break;
            case SCHED_FIFO:
                printf("Policy: SCHED_FIFO\n");
                break;
            case SCHED_RR:
                printf("Policy: SCHED_RR\n");
                break;
            default:
                printf("Policy: Unknown Policy\n");
                break;
        }
    }

    return 0;
}