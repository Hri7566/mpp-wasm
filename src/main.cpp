#include "main.h"

FFI bool mpp_load()
{
    EM_ASM_INT({
        var AudioContext = window.AudioContext || window.webkitAudioContext;
        var ctx = new AudioContext();
        var sr = ctx.sampleRate;
        ctx.close();
        return sr;
    });

    return true;
}

static const char *prefix = "-";

FFI void mpp_client_a(const char *_id, const char *name, const char *color, const char *a, int32_t time)
{
    if (strncmp(prefix, a, strlen(prefix)) != 0)
        return;

    sendChat("command goes here");
}
