/*
 *  project 10-ir-remote
 *
 *  ir-convert.h
 *      Prototype of function to decode IR remote keys
 */

#define IN_TEST 0

#define DEL     0x7f
#define NUL     0

int ir_convert(unsigned long code);

