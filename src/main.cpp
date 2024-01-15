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

void substr(const char *str, int pos1, int pos2, char *substring)
{
    int len = strlen(str);

    if (pos2 > len || pos2 < 0)
        pos2 = len;

    if (pos1 < 0)
        pos1 = 0;

    for (int i = pos1; i < pos2; i++)
    {
        substring[i - pos1] = str[i];
    }
}

FFI void mpp_client_a(const char *_id, const char *name, const char *color, const char *a, int32_t time)
{
    if (strncmp(prefix, a, strlen(prefix)) != 0)
        return;

    int firstSpace;

    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] == ' ')
        {
            firstSpace = i;
            break;
        }
    }

    char cmd[firstSpace];

    substr(a, 1, firstSpace, cmd);
    sendChat(cmd);

    // BotCommand *foundCommand;

    // for (int i = 0; i < sizeof(commands) / sizeof(*commands); i++)
    // {
    //     BotCommand *command = &(commands[i]);
    //     command->id;
    // }

    // if (foundCommand == NULL)
    //     return;

    // const char *out = foundCommand->callback();
    // sendChat(out);
}
