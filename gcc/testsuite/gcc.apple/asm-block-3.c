/* APPLE LOCAL file CW asm blocks */
/* Test single line asms */

/* { dg-do compile { target powerpc*-*-darwin* i?86*-*-darwin* } } */
/* { dg-options "-fasm-blocks" } */

void
bar ()
{
  asm { nop };
}
