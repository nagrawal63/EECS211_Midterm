#include "kernel/types.h"
#include "user/user.h"

char * argv[] = {"ls", ""};

int main(void) {
  // printf("inside main: %d\n", getpid());
  int child_pid;
  if ((child_pid = fork()) == 0) {
    // printf("child process 1 %d\n", getpid());
    exec(argv[0], argv);
    // printf("child 1 done %d\n", getpid());
  }
  wait(0);
  if ((child_pid = fork()) == 0) {
    // printf("child process 2: %d\n", getpid());
    exec(argv[0], argv);
    // printf("child 2 done: %d\n", getpid());
  }
  wait(0);
  // printf("main done: %d\n", getpid());
  exit(0);
}
