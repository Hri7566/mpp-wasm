#include "command.hpp"

Command::Command(std::function<const char *(void)> callback)
{
    this->callback = callback;
}
