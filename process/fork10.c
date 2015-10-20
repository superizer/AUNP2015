#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void child(){
  sleep(10);
  system("pstree");
  /* printf("child end\n");
  exit(0); */
  //system("pstree");
}

void parent(){
  system("pstree");
  exit(0);
  /*sleep(2);
  printf("parent call ps u\n");
  system("ps u");*/
}

int main(){
  pid_t pid;

  pid = fork();
  if(pid == -1){
    perror("fork");
    exit(-1);
  }
  if(pid==0){
    child();
  }else{
    parent();
    wait(NULL);
    /*printf("parent call ps u after wait()\n");
    system("ps u");*/
  }
  exit(0);
}
