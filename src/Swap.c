#include "Swap.h"

BITMAPINFOV3* swap(BITMAPINFO* bmi, FILE* file){
    BITMAPINFOV3_tmp *bmiV3_tmp = calloc(1, sizeof(BITMAPINFOV3_tmp));
    BITMAPINFOV3 *bmiV3 = calloc(1, sizeof(BITMAPINFOV3));
    fread(bmiV3_tmp, 1, sizeof(BITMAPINFOV3_tmp), file);
    bmiV3->size = bmi->size;
    bmiV3->width = bmi->width;
    bmiV3->height = bmi->height;
    bmiV3->planes = bmi->planes;
    bmiV3->bitCount = bmi->bitCount;
    bmiV3->compression = bmiV3_tmp->compression;
    bmiV3->sizeImage = bmiV3_tmp->sizeImage;
    bmiV3->XPelsPerMeter = bmiV3_tmp->XPelsPerMeter;
    bmiV3->YPelsPerMeter = bmiV3_tmp->YPelsPerMeter;
    bmiV3->clrUsed = bmiV3_tmp->clrUsed;
    bmiV3->clrImportant = bmiV3_tmp->clrImportant;
    free(bmiV3_tmp);
    return bmiV3;
}