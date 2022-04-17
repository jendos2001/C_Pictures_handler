#ifndef STRUCTURES_H
#define STRUCTURES_H

#pragma pack(push, 1)
typedef struct{
    unsigned char b;
    unsigned char g;
    unsigned char r;
}RGB;

typedef struct{
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offBits;
}BITMAPFILEHEADER;

typedef struct {
    unsigned int size;
    unsigned int width;
    unsigned int height;
    unsigned short planes;
    unsigned short bitCount;
    unsigned int compression;
    unsigned int sizeImage;
    unsigned int XPelsPerMeter;
    unsigned int YPelsPerMeter;
    unsigned int clrUsed;
    unsigned int clrImportant;
}BITMAPINFOV3;

typedef struct {
    unsigned int size;
    unsigned int width;
    unsigned int height;
    unsigned short planes;
    unsigned short bitCount;
}BITMAPINFO;

typedef struct {
    unsigned int compression;
    unsigned int sizeImage;
    unsigned int XPelsPerMeter;
    unsigned int YPelsPerMeter;
    unsigned int clrUsed;
    unsigned int clrImportant;
}BITMAPINFOV3_tmp;
#pragma pack(pop)

struct Commands{
    int n;
    int x_c;
    int y_c;
    int x1;
    int y1;
    int x2;
    int y2;
    int radius;
    int l;
    int w;
    int red;
    int green;
    int blue;
    int fill;
    int red_fill;
    int green_fill;
    int blue_fill;
    int alpha;
    int component_value;
    int option;
    int error;
    int output;
};

#endif