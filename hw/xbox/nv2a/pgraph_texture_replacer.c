#include "pgraph_texture_replacer.h"

//TODO: Use a more generic function instead of RGBSUrface, (glreadpixels/GLGetteximage?)
void texture_download(TextureBinding *texture, SurfaceBinding *surface)
{
    SDL_surface * surf;
    char filename[20];

    snprintf(filename, sizeof(filename), "%lu.bmp", surface->vram_addr);
    surf = SDL_CreateRGBSurfaceFrom(surface->texture, surface->width, surface->height, 
                                    surface->shape.color_format*surface->fmt.bytes_per_pixel, 
                                    surface->width*surface->shape.color_format, 0,0,0,0);
    SDL_SaveBMP(surf, filename);  
    SDL_FreeSurface(surf);
    free(surface->texture);
    surface->texture = NULL; 
}

void texture_upload(TextureBinding *texture, SurfaceBinding *surface)
{

}



