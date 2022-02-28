#include "debug.h"
#include "defs.h"
#include "proc.h"

#define NULL 0

struct proc_time proc_times[PROC_TIMES_SIZE];

int get_ancestor_pid(const struct proc * p) {
    struct proc * it = (struct proc *)p;
    while (strncmp(it->parent->name, p->name, 16) == 0) {
        it = it->parent;
    }
    return it->pid;
}

struct proc_time * get_proc_time(const struct proc * p) {
    if (!p || strncmp(p->name, "init", 16) == 0 || strncmp(p->name, "initcode", 16) == 0) {
        return NULL;
    }
    for (int i = 0; i < PROC_TIMES_SIZE; i++) {
        if ((strncmp(p->name, proc_times[i].p_name, 16) == 0)) {
            // if another process with same name but different ancestor wants to profile, skip it
            if (proc_times[i].parent_pid && get_ancestor_pid(p) != proc_times[i].parent_pid) {
                return NULL;
            }
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
