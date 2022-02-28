#include "kernel/types.h"
#define MAX_N 10000000000
int main(void) {
    volatile uint64 i=0;
    while( i < MAX_N) {
        i++;
    }
    return 0;
}