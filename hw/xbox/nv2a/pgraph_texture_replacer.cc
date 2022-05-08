#include "pgraph_texture_replacer.h"

void texture_download(TextureBinding *texture, ColorFormatInfo *f, SurfaceBinding *surface)
{
    void *pixels = surface->texture;
    char fname = reinterpret_cast<char>(surface->vram_addr);
    const char *output_dir = "./out";
    std::vector<uint8_t> png;

    fpng_encode_image_to_memory(pixels, surface->width, surface->height, 0, png);
    char *path = snprintf("%s/%x", output_dir, fname);
    FILE *fd = qemu_fopen(path, "wb");
    int s = fwrite(png.data(), png.size(), 1, fd);
    fclose(fd);

    /*
    pixels = (void*)g_malloc(surface->height * surface->width * 4);
    glGetTexImage(texture->gl_target, 0, f->gl_format, f->gl_type, pixels);*/
}

void texture_upload(TextureBinding *texture, ColorFormatInfo *f, SurfaceBinding *surface)
{

}



