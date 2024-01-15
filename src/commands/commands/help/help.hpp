#ifndef _HELP_H
#define _HELP_H

#include "../../../commands/command.hpp"

const char *help_ptr();
static BotCommand help("help", help_ptr);

#endif
