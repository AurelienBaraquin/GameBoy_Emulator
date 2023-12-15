#include <cpu.h>
#include <mem.h>

void nop(void) {
    // Do nothing except increment the program counter by 1
}

void halt(void) {
    halted = 1;
}

void di(void) {
    memoryBus[IE] = 0;
}

void ei(void) {
    memoryBus[IE] = 1;
}
