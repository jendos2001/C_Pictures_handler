#include "FreeMemory.h"

void FreeMemory(RGB** image, BITMAPINFOV3* bmiV3){
    for(int i = 0; i < bmiV3->height; i++)
        free(image[i]);
    free(image);
    free(bmiV3);
}