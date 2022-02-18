#pragma once
#include "types.h"
#include "defs.h"

#define PROC_TIMES  16
#define true 1
#define false 0

struct proc_time {
  uint64 start_time;
  uint64 delta;
  char p_name[PROC_TIMES];
  uint8 proc_done;
};

extern struct proc_time proc_times[32];

// struct proc_times {
//   struct proc_time procTime;
//   struct proc_times *next;
// };
void proc_times_init();
struct proc_time* get_proc_time(char * p_name);
void print_proc_times(void);

