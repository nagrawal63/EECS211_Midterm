#include "debug.h"
#include "defs.h"

#define NULL 0

struct proc_time proc_times[32];

void proc_times_init() {
  for (int i = 0; i < PROC_TIMES; i++) {
    proc_times[i].p_name[0] = '\0';
    proc_times[i].start_time = 0;
    proc_times[i].delta = 0;
    proc_times[i].proc_done = 0;
  }
}

struct proc_time* get_proc_time(const char * p_name) {
    // printf("In get proc time start\n");
    if (strncmp(p_name, "init", 16) == 0 || strncmp(p_name, "initcode", 16) == 0) {
    //   printf("returning from init and initcode\n");
        return NULL;
    }
//   struct proc_time * free_proc_time = NULL;
// printf("In get proc time\n");
// print_proc_times();
    for (int i = 0; i < PROC_TIMES; i++) {
        if ((strncmp(p_name, proc_times[i].p_name, 16) == 0)) {
            // printf("Matched |%s| with proc with name %s\n", p_name, proc_times[i].p_name);
            return proc_times + i; 
        } else if (proc_times[i].p_name[0] == '\0') {
            printf("Returning the index to create new proc_time\n");
            return proc_times + i;
        }
    }
  return NULL;
}

void print_proc_time(const struct proc_time *proc_t) {
    printf("Process name: %s, delta: %d, start_time: %d, done: %d\n",
             proc_t->p_name, proc_t->delta, proc_t->start_time, proc_t->proc_done);
}

void print_proc_times(void) {
    printf("---------------------------------\n");
    for(int i = 0; i < PROC_TIMES; i++) {
        if(proc_times[i].p_name[0] != '\0')
            print_proc_time(proc_times + i);
    }
    printf("---------------------------------\n");
}