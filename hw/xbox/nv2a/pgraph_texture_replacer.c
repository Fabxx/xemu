#include "pgraph_texture_replacer.h"

//TODO: Check for other texture formats: ARGB BRGA Ecc FRMO PGRAPH CODE nv097 cases and convert with SDL.
void texture_download(TextureBinding *texture, SurfaceBinding *surface)
{
    SDL_surface * surf;
    char filename[20];
    
    snprintf(filename, sizeof(filename), "%lu.bmp", surface->vram_addr);
    surf = SDL_CreateRGBSurfaceFrom(surface->texture, surface->width, surface->height, 
                                    surface->shape.color_format*surface->fmt.bytes_per_pixel, surface->width*surface->fmt.bytes_per_pixel, 0,0,0,0);
    SDL_SaveBMP(surf, filename);                                /*multiplying the color format retreived (aka color channels) multiplied by the 
                                                                color depth (aka the color combinations, 8 bytes, 4 bytes ecc). Need to use a more generic
                                                                SDL function to store other formats and not RGB only.*/
    SDL_FreeSurface(surf);
    free(surface->texture);
    surface->texture = NULL;
}
   

void texture_upload(TextureBinding *texture, SurfaceBinding *surface)
{

}



