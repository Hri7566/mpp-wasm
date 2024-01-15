#include "command.hpp"

BotCommand::BotCommand(const char *id, std::function<const char *(void)> callback)
{
    this->id = id;
    this->callback = callback;
}
