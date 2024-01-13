#ifndef _UTIL_H
#define _UTIL_H

#include <emscripten/emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/val.h>

#define EXTERN extern "C"
#define FFI EXTERN EMSCRIPTEN_KEEPALIVE
#define JS EM_JS

using namespace emscripten;

#endif
