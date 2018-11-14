#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main( int argc, char** argv )
{
    if (argc < 2) {
        printf("Ussage %s [dir]\n", argv[0]);
        return 1;
    }

    DIR *dp;
    struct dirent *ep;

    dp = opendir (argv[1]);
    if (dp != NULL) {
      while (ep = readdir (dp)) {
        printf ("File:\t%s\n", ep->d_name);
      }
      
      closedir (dp);
    } else {
        return 1;
    }

  return 0;


}