#include "debug.h"
#include "defs.h"

#define NULL 0

struct proc_time proc_times[PROC_TIMES_SIZE];

struct proc_time* get_proc_time(const char * p_name) {
    // printf("In get proc time start\n");
    if (strncmp(p_name, "init", 16) == 0 || strncmp(p_name, "initcode", 16) == 0) {
    //   printf("returning from init and initcode\n");
        return NULL;
    }
//   struct proc_time * free_proc_time = NULL;
// printf("In get proc time\n");
// print_proc_times();
    for (int i = 0; i < PROC_TIMES_SIZE; i++) {
        if ((strncmp(p_name, proc_times[i].p_name, 16) == 0)) {
            // printf("Matched |%s| with proc with name %s\n", p_name, proc_times[i].p_name);
            return proc_times + i;
        } else if (proc_times[i].p_name[0] == '\0') {
            #ifdef VPRINT
            printf("Returning the index to create new proc_time\n");
            #endif
            return proc_times + i;
        }
    }
  return NULL;
}

void print_proc_time(const struct proc_time *proc_t) {
    printf("p_name: %s ", proc_t->p_name);
    printf("avg_exec_time: %s ", proc_t->avg_exec_time);
    printf("start_time: %s ", proc_t->start_time);
    printf("num_runs: %d ", proc_t->num_runs);
    printf("done: %d\n", proc_t->done);
}

void print_proc_times(void) {
    printf("---------------------------------\n");
    for(int i = 0; i < PROC_TIMES_SIZE; i++) {
        if(proc_times[i].p_name[0] != '\0')
            print_proc_time(proc_times + i);
    }
    printf("---------------------------------\n");
}
