#pragma once
#include "types.h"
#include "defs.h"
#include "param.h"

#define PROC_NAME_SIZE  16
#define PROC_TIMES_SIZE 32
#define EXEC_TIMES 10
#define true 1
#define false 0
#define REGINTERVAL 1000000
#define LARGEINTERVAL 2000000
#define SMALLINTERVAL 500000

//extern uint64 timer_scratch[NCPU][5];

//#define VPRINT 1

typedef uint8 bool;

// TODO: Create a map for PID -> exec_time index in case a process yields and a new process starts
struct proc_time {
  char p_name[PROC_NAME_SIZE];
  uint64 start_time;
  uint64 exec_times[EXEC_TIMES];
  uint64 avg_exec_time;
  uint32 num_runs;

  uint32 parent_pid;
  bool done;
};

struct yield_count {
  char p_name[PROC_NAME_SIZE];
  uint32 num_yields;
  uint64 interval;

};

extern struct yield_count proc_yield_counts[32];
extern struct proc_time proc_times[32];

struct yield_count* get_yield_count (const char * p_name);
void set_interval(struct yield_count* p);

struct proc_time* get_proc_time(const char * p_name);
void print_proc_times(void);
void print_proc_time(const struct proc_time *proc_t);
