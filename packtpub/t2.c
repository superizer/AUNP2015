#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int main(int argc, char **argv){
  FILE *f;
  char buf[2048];
  int count = 0;

  f = fopen(argv[1], "r");
  if(f == (FILE *)NULL){
    perror("fopen");
    exit(-1);
  }
  
  while(1){
    char *s = fgets(buf, sizeof(buf), f);
    if(s == (char *)NULL)
      break;
    if(++count == 600){
      
      // Remove </h2>
      char *end = buf+ strlen(buf) - 6;
      *end = 0;

      printf("%s\n",trimwhitespace(buf));
    }
    //printf("%d: %s",++count,buf);
  }

  fclose(f);


  return 0;
}
