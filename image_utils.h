/* Image manipulation functions
 *
 * Project : minidlna
 * Website : http://sourceforge.net/projects/minidlna/
 * Author  : Justin Maggard
 *
 * MiniDLNA media server
 * Copyright (C) 2009  Justin Maggard
 *
 * This file is part of MiniDLNA.
 *
 * MiniDLNA is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * MiniDLNA is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MiniDLNA. If not, see <http://www.gnu.org/licenses/>.
 */
#include <inttypes.h>

#define ROTATE_NONE 0x0
#define ROTATE_90   0x1
#define ROTATE_180  0x2
#define ROTATE_270  0x4

#ifdef HAVE_LIBPNG
/* background color for images w/transparency */
#define BGCOLOR 0x7f7f7f
#endif

typedef uint32_t pix;

typedef struct {
	int32_t width;
	int32_t height;
	pix     *buf;
} image_s;

void
image_free(image_s *pimage);

int
image_get_jpeg_date_xmp(const char * path, char ** date);

int
image_get_jpeg_resolution(const char * path, int * width, int * height);

image_s *
image_new_from_jpeg(const char *path, int is_file, const uint8_t *ptr, int size, int scale, int rotate);

#ifdef HAVE_LIBPNG
image_s *
image_new_from_png(const char *path, int is_file, const uint8_t *ptr, int size, int scale, int rotate, int *alpha);

size_t
image_save_to_png (const image_s *img, char *path,
		uint8_t **buf, int alpha, int compression);

struct _iu_png_io_struct {
    FILE *fp;
    uint8_t *buf, *bufp;
    size_t count;
};
#endif

image_s *
image_resize(image_s * src_image, int32_t width, int32_t height);

unsigned char *
image_save_to_jpeg_buf(image_s * pimage, int * size);

char *
image_save_to_jpeg_file(image_s * pimage, char * path);

void
image_bgcolor_composite (image_s *img, uint32_t bgcolor);
