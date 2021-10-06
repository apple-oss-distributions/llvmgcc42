/* { dg-do compile { target lp64 } } */
/* APPLE LOCAL 64 bit default */
/* { dg-require-effective-target ilp32 } */
/* { dg-options "-O2 -fstack-protector-all -mcmodel=kernel" } */

void test1 (int x)
{
  char p[40];
  int i;
  for (i=0; i<40; i++)
	p[i] = x;
}

/* { dg-final { scan-assembler-not "%fs" } } */
