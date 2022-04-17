#include "ReadImage.h"

RGB** ReadImage(BITMAPINFOV3* bmiV3, FILE* file){
    RGB **image = malloc(bmiV3->height * sizeof(RGB*));
    for (int i = 0; i < bmiV3->height; i++){
        image[i] = malloc(bmiV3->width * sizeof(RGB) + (bmiV3->width) % 4);
        fread(image[i],  bmiV3->width * sizeof(RGB) + (bmiV3->width) % 4, 1, file);
    }
    return image;
}