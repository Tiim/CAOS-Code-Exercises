
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>


int main( int argc, char** argv )
{
    if (argc < 2) {
        printf("Ussage %s [file]\n", argv[0]);
        return 1;
    }

    char* file = argv[1];

    struct stat file_stat;

    if (stat(file, &file_stat) < 0){    
        return 1;
    }

    printf("%s\n\n",file);
    printf("Size: \t\t\t%li bytes\n",file_stat.st_size);
    printf("Type: \t\t\t%u\n", file_stat.st_mode);
    printf("Permissions: \t\t%s%s%s%s%s%s%s%s%s%s\n",
        S_ISDIR(file_stat.st_mode) ? "d" : "-",
        (file_stat.st_mode & S_IRUSR) ? "r" : "-",
        (file_stat.st_mode & S_IWUSR) ? "w" : "-",
        (file_stat.st_mode & S_IRGRP) ? "r" : "-",
        (file_stat.st_mode & S_IWGRP) ? "w" : "-",
        (file_stat.st_mode & S_IXGRP) ? "x" : "-",
        (file_stat.st_mode & S_IROTH) ? "r" : "-",
        (file_stat.st_mode & S_IWOTH) ? "w" : "-",
        (file_stat.st_mode & S_IXUSR) ? "x" : "-",
        (file_stat.st_mode & S_IXOTH) ? "x" : "-"
    );
    printf("Owner ID: \t\t%u\n", file_stat.st_uid);
    
    char buff_time[20];
    strftime(buff_time, 20, "%Y-%m-%d %H:%M:%S", localtime(&file_stat.st_mtime));
    printf("Last modified: \t\t%s\n",buff_time );


}