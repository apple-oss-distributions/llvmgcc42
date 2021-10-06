/* APPLE LOCAL file radar 6379842 - blocks */
/* { dg-do compile } */
/* { dg-options "-ObjC -fblocks -m64 -fobjc-gc-only" { target powerpc*-*-darwin* i?86*-*-darwin* } } */
/* { dg-options "-ObjC -fblocks -fobjc-gc-only"  {target arm*-*-darwin* } } */

@interface Thing  {}

@property void(^someBlock)(void);   /* { dg-warning "\\'copy\\' attribute must be specified for the block property" } */
@property(copy)  void(^OK)(void);


@end
