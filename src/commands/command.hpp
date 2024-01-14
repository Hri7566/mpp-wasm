#ifndef _COMMANDS_H
#define _COMMANDS_H

#include <string>
#include <functional>

#define CommandCallback std::function<const char *(void)>

class Command
{
public:
    Command(CommandCallback callback);
    CommandCallback callback;
};

#endif
