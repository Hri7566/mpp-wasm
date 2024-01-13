#ifndef _FFI_H
#define _FFI_H

#include "util.h"

JS(void, sendChat, (const char *str), {MPP.client.sendArray([ {
       m : "a",
       message : `\u034f${UTF8ToString(str)}`
   } ])});

#endif
