#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  int pid;
  printf("before fork\n");
  pid = fork();
  printf("after fork\n");
  sleep(2);
  exit(0);
}
