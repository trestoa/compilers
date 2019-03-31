#include "stdio.h"

#define N 2

extern void asmb(unsigned long *a, unsigned long *b, unsigned long c, unsigned long n);

void printbits(unsigned long* x, unsigned long n)
{
    for(int j = 0; j < n; j++) {
        for(int i=sizeof(x[j])<<3; i; i--)
            putchar('0'+((x[j]>>(i-1))&1));
    }
    
    putchar('\n');
    //printf("%016lx%016lx\n", x[1], x[0]);
}

int main(void) {
    unsigned long a[]={0x3e6643906dfed2fdL, 0x0123456789abcdefL};
    unsigned long b[N];
    printbits(a, N);
    
    asmb(a, b, 1, N);
    
    printbits(b, N);
}
