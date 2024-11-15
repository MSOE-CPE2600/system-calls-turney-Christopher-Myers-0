/*******************************************************************************
Filename: finfo.c
Name: Christopher Myers
Assignment: Lab 9
Date: 11/12/2024
Course: CPE 2600-121
*******************************************************************************/

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int pOutFType(unsigned int type);
int pOutFPerm(unsigned int type);

int main(int argc, char* argv[])
{
    if(argc == 1) {
        printf("No file path entered\n");
        return -1;
    }

    struct stat fileStats;
    if(stat(argv[1], &fileStats) == 0) {

        pOutFType(fileStats.st_mode & S_IFMT);
        pOutFPerm(fileStats.st_mode);
        printf("User Id of Owner: %d\n", fileStats.st_uid);
        printf("Size in Bytes: %ld\n", fileStats.st_size);

        time_t lastModifiedSec = fileStats.st_mtime;
        struct tm lastModified = *localtime(&lastModifiedSec);
        printf("Last Modified: %dh:%dm:%ds %dd %dmth %dyr\n",
            lastModified.tm_hour,
            lastModified.tm_min,
            lastModified.tm_sec,
            lastModified.tm_mday,
            lastModified.tm_mon,
            lastModified.tm_year + 1900);
    } else {
        printf("The file info could not be read\n");
    }

    return 0;
}

int pOutFType(unsigned int type) {
    printf("File type: ");
    switch(type) {
        case S_IFSOCK:
            printf("Socket\n");
            break;
        case S_IFLNK:
            printf("Symbolic link\n");
            break;
        case S_IFREG:
            printf("Regular file\n");
            break;
        case S_IFBLK:
            printf("Block device\n");
            break;
        case S_IFDIR:
            printf("Directory\n");
            break;
        case S_IFCHR:
            printf("Character device\n");
            break;
        case S_IFIFO:
            printf("FIFO\n");
            break;
        default:
            printf("Unknown file type\n");
            break;
    }
    return 0;
}

int pOutFPerm(unsigned int perm) {

    printf("File Permissions: usr:");
    
    if(perm & S_IRUSR) { 
        printf("r");
    } else { 
        printf("-");
    }
    if(perm & S_IWUSR) { 
        printf("w");
    } else { 
        printf("-");
    }
    if(perm & S_IXUSR) { 
        printf("x");
    } else { 
        printf("-");
    }
    printf(" grp:");
    if(perm & S_IRGRP) { 
        printf("r");
    } else { 
        printf("-");
    }
    if(perm & S_IWGRP) { 
        printf("w");
    } else { 
        printf("-");
    }
    if(perm & S_IXGRP) { 
        printf("x");
    } else { 
        printf("-");
    }
    printf(" oth:");
    if(perm & S_IROTH) { 
        printf("r");
    } else { 
        printf("-");
    }
    if(perm & S_IWGRP) { 
        printf("w");
    } else { 
        printf("-");
    }
    if(perm & S_IXGRP) { 
        printf("x");
    } else { 
        printf("-");
    }
    printf("\n");

    return 0;
}