#include "pgraph_texture_replacer.h"

//TODO: use glreadpixels to obtain textures form framebuffer and find another method to save them
//SDL does not support DXT and other compressed texture types.
void texture_download(SurfaceBinding *surface)
{
    SDL_Surface * surf;
    char filename[20];

        snprintf(filename, sizeof(filename), "%lu.bmp", surface->vram_addr);

        if (surface->shape.color_format == NV097_SET_TEXTURE_FORMAT_COLOR_LU_IMAGE_R8G8B8A8) {
            surf = SDL_CreateRGBSurfaceFrom(surface->texture, surface->width, surface->height, 
                            surface->shape.color_format*surface->fmt.bytes_per_pixel, 
                            surface->width*surface->shape.color_format, 0,0,0,0);
            SDL_SaveBMP(surf, filename);  
            SDL_FreeSurface(surf);
            free(surface->texture);
            surface->texture = NULL;
            printf("Texture R8G8B8A8 exported\n");
        } else if(surface->shape.color_format == NV097_SET_TEXTURE_FORMAT_COLOR_LU_IMAGE_A8R8G8B8) {
             surf = SDL_CreateRGBSurfaceFrom(surface->texture, surface->width, surface->height, 
                            surface->shape.color_format*surface->fmt.bytes_per_pixel, 
                            surface->width*surface->shape.color_format, 0,0,0,0);
            SDL_SaveBMP(surf, filename);  
            SDL_FreeSurface(surf);
            free(surface->texture);
            surface->texture = NULL;
            printf("Texture A8R8G8B8 exported\n");
        } else if (surface->shape.color_format == NV097_SET_TEXTURE_FORMAT_COLOR_LU_IMAGE_A8B8G8R8) {
            surf = SDL_CreateRGBSurfaceFrom(surface->texture, surface->width, surface->height, 
                            surface->shape.color_format*surface->fmt.bytes_per_pixel, 
                            surface->width*surface->shape.color_format, 0,0,0,0);
            SDL_SaveBMP(surf, filename);  
            SDL_FreeSurface(surf);
            free(surface->texture);
            surface->texture = NULL;
            printf("Texture A8B8G8R8 exported\n");
        } else {
            printf("nothing here to extract soz\n");
        }
}      

void texture_upload(SurfaceBinding *surface)
{

}



