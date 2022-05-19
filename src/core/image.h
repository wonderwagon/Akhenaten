#ifndef CORE_IMAGE_H
#define CORE_IMAGE_H

#include <SDL_render.h>
#include <vector>
#include "core/encoding.h"
#include "core/image_group.h"
#include "graphics/color.h"
#include "file.h"

#define IMAGE_FONT_MULTIBYTE_OFFSET 10000
#define IMAGE_FONT_MULTIBYTE_TRAD_CHINESE_MAX_CHARS 2188
#define IMAGE_FONT_MULTIBYTE_SIMP_CHINESE_MAX_CHARS 2130
#define IMAGE_FONT_MULTIBYTE_KOREAN_MAX_CHARS 2350

#define IMAGE_ATLAS_BIT_OFFSET 28
#define IMAGE_ATLAS_BIT_MASK 0x0fffffff

enum {
    IMAGE_TYPE_WITH_TRANSPARENCY = 0,
    IMAGE_TYPE_ISOMETRIC = 30,
    IMAGE_TYPE_MOD = 40
};

/**
 * @file
 * Image functions
 */

/**
 * Image metadata
 */

#define PAK_HEADER_INFO_BYTES 80
#define PAK_BMP_NAME_SIZE 200
#define PAK_GROUPS_MAX 300
#define PAK_HEADER_SIZE_BASE PAK_HEADER_INFO_BYTES + (PAK_GROUPS_MAX * 2) // total = 680 bytes

typedef struct image;

typedef struct {
    SDL_Texture *texture;
    std::vector<image*> images;
    color_t *pixel_buffer;
    int bmp_size;
    int width;
    int height;
} atlas_data_t;

struct image {
    char *pak_name;
    int sgx_index;
    int sgx_data_offset;
    int data_length;
    int uncompressed_length;
    int unk00; //
    int offset_mirror;
    image *mirrored_img;
    //
    int width;
    int height;
    int unk01; //
    int unk02; //
    int unk03; //
    struct {
        int num_sprites;
        int unk04; //
        int sprite_x_offset;
        int sprite_y_offset;
        int unk05; //
        int unk06; //
        int unk07; //
        int unk08; //
        int unk09; //
        bool can_reverse;
        int unk10; //
        int speed_id;
    } animation;
    int type;
    bool is_fully_compressed;
    bool is_external;
    int top_height;
    int unk11; //
    int unk12; //
    struct {
        char *name;
        int group_id;
        int entry_index;
    } bmp;
    int unk13; //
    // (anim speed id)
    int unk14; //
    int unk15; //
    int unk16; //
    int unk17; //
    int unk18; //

    int unk19; //
    int unk20; //

    struct {
        int index;
        int x_offset;
        int y_offset;
        atlas_data_t *p_atlas;
    } atlas;

    color_t *pixel_data;
};

typedef struct {
    int width;
    int height;
} texture_size_t;

class imagepak {
    int version;
    int entries_num;
    int groups_num;
    char *bmp_names;
    int num_bmp_names;
    uint16_t *group_image_ids;
    std::vector<image> images_array;

    bool SHOULD_LOAD_SYSTEM_SPRITES;
    bool SHOULD_CONVERT_FONTS;

    bool load_pak(const char *pak_name, int starting_index);

public:
    char name[MAX_FILE_NAME];
    std::vector<atlas_data_t> atlas_pages;

    int global_image_index_offset = 0;

    imagepak(const char *pak_name, int starting_index, bool SYSTEM_SPRITES = false, bool FONTS = false);
    ~imagepak();

    int get_entry_count();
    int get_global_image_index(int group);
    const image *get_image(int id, bool relative = false);
};

extern int terrain_ph_offset;

void image_data_init();

bool image_load_main_paks(int climate_id, int is_editor, int force_reload);
bool image_set_font_pak(encoding_type encoding);
bool image_set_enemy_pak(int enemy_id);

int image_id_from_group(int collection, int group, int pak_cache_idx = -1);

const image *image_get(int id, int mode = 0);
const image *image_letter(int letter_id);
const image *image_get_enemy(int id);
//const color_t *image_data(int id);
const color_t *image_data_letter(int letter_id);
const color_t *image_data_enemy(int id);

#endif // CORE_IMAGE_H
