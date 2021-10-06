/* APPLE LOCAL file 5932809 */
/* { dg-do run { target *-*-darwin[1-2][0-9]* } } */
/* { dg-options "-fblocks" } */
/* { dg-skip-if "" { powerpc*-*-darwin* } { "-m64" } { "" } } */

#include <stdio.h>
void * _NSConcreteStackBlock;
void _Block_byref_assign_copy(void * dst, void *src){}
void _Block_byref_release(void*src){}
extern void exit(int);

typedef double (^myblock)(int);


double test(myblock I) {
  return I(42);
}

int main() {
  __block int x = 1;
  __block int y = 2;
  double res = test(^(int z){y = x+z; return (double)x; }); 
  printf("result = %f  x = %d y = %d\n", res, x, y);
  if (x != 1 || y != 43)
   exit(1);

  res = test(^(int z){x = x+z; return (double)y; }); 
  printf("result = %f  x = %d y = %d\n", res, x, y);
  if (x != 43 || y != 43)
    exit(1);
  return 0;
}

