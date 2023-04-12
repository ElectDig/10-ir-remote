/*
 *  Project 10-ir-remote
 *
 *  ir_convert.cpp
 *      function to decode IR remote keys
 *      Uses table in ir_convert.def
 */

#include <Arduino.h>

#include "ir_convert.h"
#include "ir_convert.def"

int
ir_convert(unsigned long code)
{
    const irconv_t *p;

    for( p = irconv_table; p->code != 0; ++p )
        if( p->code == code )
            return p->key;
    return NUL;
}


