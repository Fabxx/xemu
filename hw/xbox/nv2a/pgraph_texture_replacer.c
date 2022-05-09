#include "pgraph_texture_replacer.h"

//TODO: Check for other texture formats: ARGB BRGA Ecc FRMO PGRAPH CODE nv097 cases and convert with SDL.
void texture_download(TextureBinding *texture, SurfaceBinding *surface)
{
     SDL_surface * surf;
     char filename[20];

    snprintf(filename, sizeof(filename), "%lu.bmp", surface->vram_addr);
   
   
   switch(surface->shape.color_format) {
        case NV097_SET_TEXTURE_FORMAT_COLOR_SZ_Y8:
        surf = SDL_CreateY






       case NV097_SET_TEXTURE_FORMAT_COLOR_SZ_R8G8B8A8:
       surf = SDL_CreateRGBSurfaceFrom(surface->texture, surface->width, surface->height, 8*4, surface->width*4, 0,0,0,0);
       SDL_SaveBMP(surf, filename);
       break;
       
   }
   

   
    
    SDL_FreeSurface(surf);
    free(surface->texture);

    surface->texture = NULL;

    
}

void texture_upload(TextureBinding *texture, SurfaceBinding *surface)
{

}



