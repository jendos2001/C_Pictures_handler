#include "WriteImage.h"

void WriteImage(BITMAPFILEHEADER* bmfh, BITMAPINFOV3* bmiV3, RGB** image, char* outputfile){
    FILE *file_write = fopen(outputfile, "wb");
    fwrite(bmfh, sizeof(BITMAPFILEHEADER), 1, file_write);
    fwrite(bmiV3,  sizeof(BITMAPINFOV3), 1, file_write);
    for (int i = 0; i < bmiV3->height; i++){
        fwrite(image[i], sizeof(RGB), bmiV3->width, file_write);
        for (int j = 0; j < bmiV3->width % 4; j++){
            fputc(0, file_write);
        }
    }
    fclose(file_write);
}