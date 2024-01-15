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
    int prefixLen = strlen(prefix);
    char sub_prefix[prefixLen];
    substr(a, 0, prefixLen, sub_prefix);

    if (strncmp(prefix, a, strlen(prefix)) != 0)
        return;

    int len = strlen(a);
    int firstSpace = len;

    for (int i = 0; i < len; i++)
    {
        if (a[i] == ' ')
        {
            firstSpace = i;
            break;
        }
    }

    char cmd[firstSpace];

    for (int i = 0; i < firstSpace; i++)
    {
        cmd[i] = 0;
    }

    substr(a, 1, firstSpace, cmd);

    BotCommand *foundCommand;

    for (int i = 0; i < sizeof(commands) / sizeof(*commands); i++)
    {
        BotCommand *command = &(commands[i]);
        if (strcmp(command->id, cmd) == 0)
        {
            foundCommand = command;
            break;
        }
    }

    if (foundCommand == NULL)
        return;

    char out[512];
    for (int i = 0; i < 512; i++)
    {
        out[i] = 0;
    }

    foundCommand->callback(out);
    sendChat(out);
}
