#include "pgraph_texture_replacer.h"


void texture_download(TextureBinding *texture, SurfaceBinding *surface)
{
    void *pixels = surface->texture;
     char filename[20];

    snprintf(filename, sizeof(filename), "%lu.bmp", surface->vram_addr);
   
    SDL_Surface * surf = SDL_CreateRGBSurfaceFrom(pixels, surface->width, surface->height, 8*4, surface->width*4, 0,0,0,0);
    SDL_SaveBMP(surf, filename);
    SDL_FreeSurface(surf);

    free(pixels);
    free(surface->texture);
    
}

void texture_upload(TextureBinding *texture, SurfaceBinding *surface)
{

}



