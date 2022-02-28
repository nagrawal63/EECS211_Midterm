#include "kernel/types.h"
#include "user/user.h"
#define MAX_N 30000000000ll
int main(void) {
    volatile uint64 i=0;
    while( i < MAX_N) {
        i++;
    }
    exit(0);
    
}