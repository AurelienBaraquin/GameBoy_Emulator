#include <cpu.h>

void nop(void) {
    // Do nothing except increment the program counter by 1
}

void halt(void) {
    halted = 1;
}

void di(void) {
    ime = 0;
}

void ei(void) {
    ime = 1;
}
