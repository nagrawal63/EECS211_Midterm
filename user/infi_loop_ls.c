#include "kernel/types.h"
#include "user/user.h"

#define MAX_N 10000000000
int main(void) {
    volatile uint64 i=0;
    while( i < MAX_N) {
        i++;
    }
    exit(0);
}
