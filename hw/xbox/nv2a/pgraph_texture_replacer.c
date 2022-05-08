#include "pgraph_texture_replacer.h"


void texture_download(TextureBinding *texture, SurfaceBinding *surface)
{
     char filename[20];

    snprintf(filename, sizeof(filename), "%lu.bmp", surface->vram_addr);
   
    SDL_Surface * surf = SDL_CreateRGBSurfaceFrom(surface->texture, surface->width, surface->height, 8*4, surface->width*4, 0,0,0,0);
    SDL_SaveBMP(surf, filename);
    SDL_FreeSurface(surf);
    free(surface->texture);

    surface->texture = NULL;
    
    
}

void texture_upload(TextureBinding *texture, SurfaceBinding *surface)
{

}



