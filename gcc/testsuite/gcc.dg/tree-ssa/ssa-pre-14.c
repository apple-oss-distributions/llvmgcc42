/* { dg-do compile } */ 
/* { dg-options "-O2 -fdump-tree-optimized" } */
/* LLVM LOCAL test not applicable */
/* { dg-require-fdump "" } */
extern __SIZE_TYPE__ strlen (const char *) __attribute__ ((__pure__));

void
foo (const char *str)
{
  __SIZE_TYPE__ a = strlen (str);
  __SIZE_TYPE__ b = strlen (str);
  if (a != b)
    link_error ();
}
/* { dg-final { scan-tree-dump-times "link_error" 0 "optimized"} } */
/* { dg-final { cleanup-tree-dump "optimized" } } */
