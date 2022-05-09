#include "pgraph_texture_replacer.h"

//TODO: Check for other texture formats: ARGB BRGA Ecc FRMO PGRAPH CODE nv097 cases and convert with SDL.
void texture_download(TextureBinding *texture, SurfaceBinding *surface)
{
    SDL_surface * surf;
    char filename[20];

    snprintf(filename, sizeof(filename), "%lu.bmp", surface->vram_addr);
    surf = SDL_CreateRGBSurfaceFrom(surface->texture, surface->width, surface->height, 
                                    surface->shape.color_format*surface->fmt.bytes_per_pixel, surface->width*surface->shape.color_format, 0,0,0,0);
    SDL_SaveBMP(surf, filename);   
}
   

   
    
    SDL_FreeSurface(surf);
    free(surface->texture);

    surface->texture = NULL;

    
}

void texture_upload(TextureBinding *texture, SurfaceBinding *surface)
{

}



