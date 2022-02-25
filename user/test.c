#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int main(void) {

  //const char filename[20] = "usertests.c\0";
  char * argv_str[] = {"ls", ""};
  int child_pid;
  if ((child_pid = fork()) != 0) {
    exec("ls", argv_str);
    wait(0);
  }
  if ((child_pid) = fork() != 0) {
    exec("ls", argv_str);
    wait(0);
  }
  exit(0);
}
