#ifndef PGRAPH_TEXTURE_REPLACER
#define PGRAPH_TEXTURE_REPLACER

#include <vector>
#include "nv2a_int.h"
#include <fpng.h>

#ifdef __cplusplus
extern "C" {
#endif

void texture_download(TextureBinding *texture, ColorFormatInfo *f, SurfaceBinding *surface);
void texture_upload(TextureBinding *texture, ColorFormatInfo *f, SurfaceBinding *surface);

#ifdef __cplusplus
}
#endif
#endif 
