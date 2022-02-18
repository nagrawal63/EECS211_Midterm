#include "debug.h"
#include <string.h>
#include <stdbool.h>

struct proc_time proc_times[32];

void proc_times_init() {
  for (int i = 0; i < PROC_TIMES; i++) {
    proc_times[i].p_name[0] = '\0';
    proc_times[i].start_time = 0;
    proc_times[i].delta = 0;
    proc_times[i].proc_done = 0;
  }
}

struct proc_time* get_proc_time(char * p_name) {
  struct proc_time * free_proc_time = NULL;
  for (int i = 0; i < PROC_TIMES; i++) {
    if (strncmp(p_name, proc_times[i].p_name, 16) == 0 && !proc_times[i].proc_done) {
      return proc_times + i; 
    } else if (proc_times[i].p_name[0] == '\0') {
      free_proc_time = proc_times + i;
    }
  }
  return free_proc_time;
}

void print_proc_times(void) {
    for(int i = 0; i < PROC_TIMES; i++) {
        
    }
}