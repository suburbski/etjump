#ifndef g_local_hpp__
#define g_local_hpp__
#include "admin/game.hpp"

// Local C++ definitions for game module

extern "C" {
#include "g_local.h"
}

#ifdef max
#undef max
#endif
#ifdef min
#undef min
#endif

extern Game game;

#endif // g_local_hpp__
