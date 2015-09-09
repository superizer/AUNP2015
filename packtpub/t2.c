#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <time.h>

#define CMD "curl -s  https://www.packtpub.com/packt/offers/free-learning > free-learning.txt"
#define FILENAME "free-learning.txt"
#define RESULTFILE "booklist.txt"

char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace(*str)) str++;
  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace(*end)) end--;

  // Write new null terminator
  *(end+1) = 0;

  return str;
}

char *remove_h2(char *str){
  char *pch = strstr(str,"</h2>");
  if(pch != NULL)
    *pch = 0;
  return str;
}

int main(int argc, char **argv){
  FILE *fo,*fw;
  char buf[2048];
  int count = 0;

  system(CMD);


  fo = fopen(FILENAME, "r");
  if(fo == (FILE *)NULL){
    perror("fopen");
    exit(-1);
  }

  fw = fopen(RESULTFILE, "a");

  struct timeval tv;
  gettimeofday(&tv, NULL);
  char* time = ctime(&tv.tv_sec);
  time[strlen(time)-1] = 0;
  //printf("%s : ", time);
  fprintf(fw,"%s : ", time);

  while(1){
    char *s = fgets(buf, sizeof(buf), fo);

    if(s == (char *)NULL)
      break;

    if(++count == 600){
      //printf("%s\n",remove_h2(trimwhitespace(buf)));
      fprintf(fw,"%s\n",remove_h2(trimwhitespace(buf)));
    }
    //printf("%d: %s",++count,buf);
  }

  fclose(fo);
  fclose(fw);

  return 0;
}
