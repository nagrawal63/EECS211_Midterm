#include "kernel/types.h"
#include "user/user.h"

char * argv1[] = {"ls", ""};
char * argv2[] = {"cat", "rm", ""};
char * argv3[] = {"echo", "bleh", ""};

int main(void) {
  int child_pid;
  if ((child_pid = fork()) == 0) {
    // printf("child process 1 %d\n", getpid());
    exec(argv1[0], argv1);
    // printf("child 1 done %d\n", getpid());
    // wait(0);
  }
  // wait(0);
  if ((child_pid = fork()) == 0) {
    // printf("child process 2: %d\n", getpid());
    exec(argv2[0], argv2);
    // printf("child 2 done: %d\n", getpid());
    // wait(0);
  }
  if ((child_pid = fork()) == 0) {
    // printf("child process 2: %d\n", getpid());
    exec(argv3[0], argv3);
    // printf("child 2 done: %d\n", getpid());
  }
  wait(0);
  exit(0);
}
