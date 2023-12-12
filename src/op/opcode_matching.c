#include <cpu.h>
#include <registers.h>

void rlc_b(void) { rlc(&registers.b); }
void rlc_c(void) { rlc(&registers.c); }
void rlc_d(void) { rlc(&registers.d); }
