#include "information.h"

void printFileHeader(BITMAPFILEHEADER header){
    printf("signature:\t%x (%hu)\n", header.type, header.type);
    printf("filesize:\t%x (%u)\n", header.size, header.size);
    printf("reserved1:\t%x (%hu)\n", header.reserved1, header.reserved1);
    printf("reserved2:\t%x (%hu)\n", header.reserved2, header.reserved2);
    printf("pixelArrOffset:\t%x (%u)\n", header.offBits, header.offBits);
}

void printInfoHeader(BITMAPINFOV3 header){
    printf("headerSize:\t%x (%u)\n", header.size, header.size);
    printf("width:     \t%x (%u)\n", header.width, header.width);
    printf("height:    \t%x (%u)\n", header.height, header.height);
    printf("planes:    \t%x (%hu)\n", header.planes, header.planes);
    printf("bitsPerPixel:\t%x (%hu)\n", header.bitCount, header.bitCount);
    printf("compression:\t%x (%u)\n", header.compression, header.compression);
    printf("imageSize:\t%x (%u)\n", header.sizeImage, header.sizeImage);
    printf("xPixelsPerMeter:\t%x (%u)\n", header.XPelsPerMeter, header.XPelsPerMeter);
    printf("yPixelsPerMeter:\t%x (%u)\n", header.YPelsPerMeter, header.YPelsPerMeter);
    printf("colorsInColorTable:\t%x (%u)\n", header.clrUsed, header.clrUsed);
    printf("importantColorCount:\t%x (%u)\n", header.clrImportant, header.clrImportant);
}