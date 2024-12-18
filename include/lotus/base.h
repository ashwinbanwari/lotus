#pragma once

#include "SDL3/SDL.h"

#include <utility>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-security"

template<typename... Args>
void fatal(SDL_PRINTF_FORMAT_STRING const char *fmt, Args&&... args)
{
    SDL_LogCritical(0, fmt, std::forward<Args>(args)...);
    abort();
}

#pragma clang diagnostic pop
