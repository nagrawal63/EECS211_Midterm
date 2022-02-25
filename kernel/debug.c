#include "debug.h"
#include "defs.h"

#define NULL 0

struct proc_time proc_times[PROC_TIMES_SIZE];
struct yield_count proc_yield_counts[32];

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


struct yield_count* get_yield_count (const char * p_name){
     if (strncmp(p_name, "init", 16) == 0 || strncmp(p_name, "initcode", 16) == 0) {
         return NULL;
    }

    
    for (int i=0; i<32; i++){
        if ((strncmp(p_name, proc_yield_counts[i].p_name, 16) == 0)) {
            return proc_yield_counts + i;
        }
        else {
            if (proc_yield_counts[i].p_name[0] == '\0') {
            #ifdef VPRINT
            printf("Returning the index to create new proc_time\n");
            #endif
            return proc_yield_counts + i;
        }
        }
    }
    return NULL;
}

void set_interval(struct yield_count*p){
    uint32 count= p->num_yields;
    uint64 cur_interval= p->interval; 
    if (count <= 5){
        if (cur_interval == REGINTERVAL){
            p->interval = LARGEINTERVAL; 
        }
        else {
            if (cur_interval == LARGEINTERVAL){
                p->interval = LARGEINTERVAL;
            }
            else {
                p->interval=REGINTERVAL;
            }
        }
    }
    else {
         if (cur_interval == REGINTERVAL){
            p->interval = SMALLINTERVAL; 
        }
        else {
            if (cur_interval == LARGEINTERVAL){
                p->interval = REGINTERVAL;
            }
            else {
                p->interval=SMALLINTERVAL;
            }
        }
    }
}