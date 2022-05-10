#include "pgraph_texture_replacer.h"

//TODO: use glreadpixels to obtain textures form framebuffer and find another method to save them
//SDL does not support DXT and other compressed texture types.
void texture_download(SurfaceBinding *surface)
{
    SDL_Surface * surf;
    char filename[13];

    snprintf(filename, sizeof(filename), "%lu.bmp", surface->vram_addr);
    surf = SDL_CreateRGBSurfaceFrom(surface->texture, surface->width, surface->height, surface->fmt.bytes_per_pixel, surface->pitch, 0,0,0,0);
    
    if (surf == NULL) { 
        fprintf(stderr, SDL_GetError());
        printf("\nFormat:%d\n", surface->shape.color_format);
        return;
    }
        SDL_SaveBMP(surf, filename);  
        SDL_FreeSurface(surf);
        surface->texture = NULL;
        printf("[EXPORT][%x]%s\n", surface->shape.color_format, surface_check(surface));
}          

void texture_upload(SurfaceBinding *surface)
{

}

const char *surface_check(SurfaceBinding *surface)
{
    const char *format_identifier;
    
    if(surface->shape.color_format == NV097_SET_SURFACE_FORMAT_COLOR_LE_X1R5G5B5_Z1R5G5B5) {
        format_identifier = "NV097_SET_SURFACE_FORMAT_COLOR_LE_X1R5G5B5_Z1R5G5B5";
    } else if (surface->shape.color_format == NV097_SET_SURFACE_FORMAT_COLOR_LE_R5G6B5) {
        format_identifier = "NV097_SET_SURFACE_FORMAT_COLOR_LE_R5G6B5";
    } else if (surface->shape.color_format == NV097_SET_SURFACE_FORMAT_COLOR_LE_X8R8G8B8_Z8R8G8B8) {
        format_identifier = "NV097_SET_SURFACE_FORMAT_COLOR_LE_X8R8G8B8_Z8R8G8B8";
    } else if (surface->shape.color_format == NV097_SET_SURFACE_FORMAT_COLOR_LE_X8R8G8B8_O8R8G8B8) {
        format_identifier = "NV097_SET_SURFACE_FORMAT_COLOR_LE_X8R8G8B8_O8R8G8B8";
    } else if (surface->shape.color_format == NV097_SET_SURFACE_FORMAT_COLOR_LE_X1A7R8G8B8_Z1A7R8G8B8) {
        format_identifier = "NV097_SET_SURFACE_FORMAT_COLOR_LE_X1A7R8G8B8_O1A7R8G8B8";
    } else if (surface->shape.color_format == NV097_SET_SURFACE_FORMAT_COLOR_LE_A8R8G8B8) {
        format_identifier = "NV097_SET_SURFACE_FORMAT_COLOR_LE_A8R8G8B8";
    } else if (surface->shape.color_format == NV097_SET_SURFACE_FORMAT_COLOR_LE_G8B8) {
        format_identifier = "NV097_SET_SURFACE_FORMAT_COLOR_LE_G8B8"; 
    } else if (surface->shape.color_format == NV097_SET_SURFACE_FORMAT_COLOR_LE_B8) {
        format_identifier = "NV097_SET_SURFACE_FORMAT_COLOR_LE_B8";
    } else if (surface->shape.color_format == NV097_SET_SURFACE_FORMAT_COLOR_LE_X1R5G5B5_O1R5G5B5) {
        format_identifier = "NV097_SET_SURFACE_FORMAT_COLOR_LE_X1R5G5B5_O1R5G5B5";
    } else {
        format_identifier = "Unknow Format";
    }
    return format_identifier;
}



