#ifndef PGRAPH_TEXTURE_REPLACER
#define PGRAPH_TEXTURE_REPLACER

#include "nv2a_int.h"
#include <SDL.h>
#include <SDL_image.h>

void texture_download(SurfaceBinding *surface);
void texture_upload(SurfaceBinding *surface);
const char *surface_check(SurfaceBinding *surface);

#endif

