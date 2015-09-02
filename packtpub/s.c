#include <stdio.h>
#include <stdlib.h>


#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>

#include <time.h>

#define FILENAME "a.txt"

int main(int argc,char **argv){
  struct stat buf;
  struct timeval tv;
  int ret;

  gettimeofday(&tv, NULL);
//  printf("time of day = %ld . %ld\n",tv.tv_sec ,tv.tv_usec);
  printf("current time of day = %s\n", ctime(&tv.tv_sec));

  ret = stat(argv[1], &buf);
  if(ret == 0)
    printf("success\n");
  else{
    perror("stat");
    exit(-1);
  }
  /*printf("ctime = %ld, mtime = %ld, atime = %ld\n",buf.st_ctime, buf.st_mtime, buf.st_atime);*/
  printf("mtime of file %s = %s\n", argv[1], ctime(&buf.st_mtime));
  return 0;
}
