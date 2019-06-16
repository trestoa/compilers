#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

extern long callchecking();
extern void printnoargs();
extern long int addtest(long int a, long int b);

static long heap[1000000];
register long *heapptr asm("%r15");

int err = 0;
int print_call = 0;

#define RET return

int call(void)
{
#include CALL
}

int main(int argc, char *argv[])
{
  long r;
  heapptr=heap;
  r=callchecking();
  if(r==0 || r==1)
    return !r;
  return r;
}

void raisesig()
{
  err = 1;
  asm("leave");
  asm("leave");
  asm("ret");
}

void printnoargs()
{
  printf("call!\n");
  print_call++;
}

long addtest(long int a, long int b) 
{
  printf("add a:%d b:%d\n", a, b);
  return a + b;
}