#include "command.hpp"

BotCommand::BotCommand(const char *id, CommandCallback callback)
{
    this->id = id;
    this->callback = callback;
}
