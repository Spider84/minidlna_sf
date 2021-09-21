#ifndef __ICONS_H__
#define __ICONS_H__

#define ICON_FIRST 0
#define ICON_LAST 3
#define ICON_PNG_LRG 0
#define ICON_PNG_SM 1
#define ICON_JPEG_LRG 2
#define ICON_JPEG_SM 3

struct icon_struct {
    unsigned char *icon[4];
    int size[4];
    int dynamic[4];
};

extern unsigned char png_sm[];
extern unsigned char png_lrg[];
extern unsigned char jpeg_sm[];
extern unsigned char jpeg_lrg[];

extern struct icon_struct icons;

#endif