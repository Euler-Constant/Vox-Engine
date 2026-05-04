#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>
#include "world.h"

void render_voxels(SDL_Renderer* renderer, World* world);

#endif
