#ifndef GB_GLYPH_H
#define GB_GLYPH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "gb_error.h"
#include "uthash.h"
#include "gb_context.h"

struct GB_Glyph {
    uint64_t key;
    int rc;
    uint32_t index;
    uint32_t font_index;
    uint32_t gl_tex_obj;
    uint32_t origin[2];
    uint32_t size[2];
    uint32_t advance;
    uint32_t bearing[2];
    uint8_t *image;
    UT_hash_handle context_hh;
    UT_hash_handle cache_hh;
};

GB_ERROR GB_GlyphMake(struct GB_Context* gb, uint32_t index, struct GB_Font *font, struct GB_Glyph **glyph_out);
GB_ERROR GB_GlyphRetain(struct GB_Glyph *glyph);
GB_ERROR GB_GlyphRelease(struct GB_Glyph *glyph);

#ifdef __cplusplus
}
#endif

#endif // GB_GLYPH_H
