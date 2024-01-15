#ifndef _HELP_H
#define _HELP_H

#include <stdlib.h>
#include <string.h>

#include "../../command.hpp"

void help_ptr(char *);
static BotCommand help("help", help_ptr);
static int numCommands = 1;

#endif
