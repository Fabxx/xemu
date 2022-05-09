#include "pgraph_texture_replacer.h"

//TODO: use glreadpixels to obtain textures form framebuffer and find another method to save them
//SDL does not support DXT and other compressed texture types.
void texture_download(SurfaceBinding *surface)
{
    SDL_Surface * surf;
    char filename[13];
    void *pixels = surface->texture;

        snprintf(filename, sizeof(filename), "%lu.bmp", surface->vram_addr);

            if (surface->shape.color_format == NV097_SET_SURFACE_FORMAT_COLOR_LE_X8R8G8B8_Z8R8G8B8) {

            surf = SDL_CreateRGBSurfaceFrom(pixels, surface->width, surface->height, surface->fmt.bytes_per_pixel, surface->pitch, 0,0,0,0);
            SDL_SaveBMP(surf, filename);  
            SDL_FreeSurface(surf);
            free(surface->texture);
            surface->texture = NULL;
            printf("Texture R8G8B8A8 exported\n");
            
        } else if(surface->shape.color_format == NV097_SET_SURFACE_FORMAT_COLOR_LE_A8R8G8B8) {
             surf = SDL_CreateRGBSurfaceFrom(pixels, surface->width, surface->height,surface->fmt.bytes_per_pixel, surface->pitch, 0,0,0,0);
            SDL_SaveBMP(surf, filename);  
            SDL_FreeSurface(surf);
            free(surface->texture);
            surface->texture = NULL;
            printf("Texture A8R8G8B8 exported\n");

        } else if (surface->shape.color_format == NV097_SET_SURFACE_FORMAT_COLOR_LE_X1R5G5B5_Z1R5G5B5) {
            surf = SDL_CreateRGBSurfaceFrom(pixels, surface->width, surface->height, surface->fmt.bytes_per_pixel, surface->pitch, 0,0,0,0);
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



