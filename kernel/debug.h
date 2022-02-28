#pragma once
#include "types.h"
#include "defs.h"
#include "proc.h"

#define PROC_NAME_SIZE  16
#define PROC_TIMES_SIZE 32
#define EXEC_TIMES 10
#define true 1
#define false 0

// #define VPRINT 0

typedef uint8 bool;

// TODO: Create a map for PID -> exec_time index in case a process yields and a new process starts
struct proc_time {
  char p_name[PROC_NAME_SIZE];
  uint64 og_start_time;
  uint64 total_exec_time;
  uint64 start_time;
  uint64 exec_times[EXEC_TIMES];
  uint64 avg_exec_time;
  uint32 num_runs;

  uint32 parent_pid;
  bool done;
};


extern struct proc_time proc_times[32];

struct proc_time* get_proc_time(const struct proc *);
void print_proc_times(void);
void print_proc_time(const struct proc_time *);
