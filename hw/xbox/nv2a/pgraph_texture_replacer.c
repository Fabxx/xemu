#include "pgraph_texture_replacer.h"

//TODO: export raw data from glreadpixels. Current error: GL_GETERROR == GL_NOERROR ASSERT in pgraph.c:995
//SDL does not support DXT and other compressed texture types.
void texture_download(NV2AState *d, SurfaceBinding *surface)
{
     char filename[13];
     PGRAPHState *pg = &d->pgraph;
     FILE *texture;

    snprintf(filename, sizeof(filename), "%lu.bmp", surface->vram_addr);

    glReadPixels(pg->surface_shape.clip_x, pg->surface_shape.clip_y, pg->surface_shape.clip_width, pg->surface_shape.clip_height, 
                surface->fmt.gl_format, surface->fmt.gl_type, surface->texture);
    texture = fopen(filename, "w");
    fwrite(surface->texture, surface->width * surface->height * surface->fmt.bytes_per_pixel, 1, texture);
    fclose(texture);
     
        surface->texture = NULL;
        printf("[EXPORT][TEXTURE][%x]%s.\n", surface->shape.color_format, surface_check(surface));
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



