#ifndef _FFI_H
#define _FFI_H

#include "util.h"

JS(void, sendChat, (const char *str), {MPP.client.sendArray([ {
       m : "a",
       message : `\u034f${UTF8ToString(str)}`
   } ])});

JS(void, c_log, (const char *str), {console.log(UTF8ToString(str))});

JS(
    bool, startsWith, (const char *str, const char *str2), { return UTF8ToString(str).startsWith(UTF8ToString(str2)); });

#endif
