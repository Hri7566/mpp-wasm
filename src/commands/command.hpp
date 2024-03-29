#ifndef _COMMANDS_H
#define _COMMANDS_H

#include <string>
#include <functional>

#define CommandCallback std::function<void(char *)>

class BotCommand
{
public:
    BotCommand(const char *id, CommandCallback callback);
    const char *id;
    CommandCallback callback;
};

#endif
