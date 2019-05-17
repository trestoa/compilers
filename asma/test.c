#include "stdio.h"

extern void asma(unsigned long *a, unsigned long *b, unsigned long c);

void printbits(unsigned long* x)
{
    for(int i=sizeof(x[1])<<3; i; i--)
        putchar('0'+((x[1]>>(i-1))&1));
    for(int i=sizeof(x[0])<<3; i; i--)
        putchar('0'+((x[0]>>(i-1))&1));
    putchar('\n');
    printf("%016lx%016lx\n", x[1], x[0]);
}

int main(void) {
    unsigned long a[]={0x0123456789abcdefL,0x3e6643906dfed2fdL};
    unsigned long b[2];
    printbits(a);
    printbits(b);
    
    asma(a, b, 64);
    
    printbits(a);
    printbits(b);
}
