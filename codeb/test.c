#include "stdio.h"

extern unsigned long f(unsigned long a, unsigned long b, unsigned long c);

int main(void) {
    printf("RES: %u\n", f(1, 4, 2));
}

void raisesig() {
    printf("Runtime error!\n");
    raise(11);
}
