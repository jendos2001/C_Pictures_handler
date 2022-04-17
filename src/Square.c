#include "Square.h"

void MakeSquareWithoutFill(BITMAPINFOV3* bmiV3, RGB** image, int x, int y, int l, int w, int r, int g, int b){
    if ((x >= bmiV3->width) || (y >= bmiV3->height) || (x < 0) || (y < 0) || (l < 0) || (w < 0))
        printf("ERROR!! Wrong coordinates or data. The start file will be written!\n");
    else if ((r < 0) || (r > 255) || (g < 0) || (g > 255) || (b < 0) || (b > 255)){
        printf("ERROR!! Wrong component. The start file will be written!\n");
    }
    else if (w > l / 2){
        printf("ERROR!! Width > side. The start file will be written!\n");
    }
    else{
        y = (int)bmiV3->height - 1 - y;
        for (int p = 0; p < w; p++){
            if (y >= p){
                for (int v = 0; v < l; v++){
                    if (x + v < bmiV3->width){
                        image[y - p][x + v].r = r;
                        image[y - p][x + v].g = g;
                        image[y - p][x + v].b = b;
                    }
                }
            }
        }
        for(int f = 0; f < (l - 2 * w); f++){
            if (y >= f + w){
                for(int k = 0; k < w; k++){
                    if (x + k < bmiV3->width) {
                        image[y - w - f][x + k].r = r;
                        image[y - w - f][x + k].g = g;
                        image[y - w - f][x + k].b = b;
                    }
                    if (x + l - k - 1 < bmiV3->width){
                        image[y - w - f][x + l - k - 1].r = r;
                        image[y - w - f][x + l - k - 1].g = g;
                        image[y - w - f][x + l - k - 1].b = b;
                    }
                }
            }
        }
        for (int p = 0; p < w; p++){
            if (y >= l - w + p){
                for (int v = 0; v < l; v++){
                    if (x + v < bmiV3->width){
                        image[y - (l - w + p)][x + v].r = r;
                        image[y - (l - w + p)][x + v].g = g;
                        image[y - (l - w + p)][x + v].b = b;
                    }
                }
            }
        }
        int size = (int)(w / sqrt(2));
        for (int j = w; j < l - w; j++){
            for(int m = 0; m < size + 1; m++){
                if ((y >= j + m) && (x + j < bmiV3->width)){
                    image[y - j - m][x + j].r = r;
                    image[y - j - m][x + j].g = g;
                    image[y - j - m][x + j].b = b;
                }
                if ((y >= j - m) && (x + j < bmiV3->width)){
                    image[y - j + m][x + j].r = r;
                    image[y - j + m][x + j].g = g;
                    image[y - j + m][x + j].b = b;
                }
                if ((y >= j - m) && (x + l - j - 1 < bmiV3->width)){
                    image[y - j + m][x + l - j - 1].r = r;
                    image[y - j + m][x + l - j - 1].g = g;
                    image[y - j + m][x + l - j - 1].b = b;
                }
                if ((y >= j + m) && (x + l - j - 1 < bmiV3->width)){
                    image[y - j - m][x + l - j - 1].r = r;
                    image[y - j - m][x + l - j - 1].g = g;
                    image[y - j - m][x + l - j - 1].b = b;
                }
            }
        }
    }
}

void MakeSquareWithFill(BITMAPINFOV3* bmiV3, RGB** image, int x, int y, int l, int w, int r, int g, int b, int r_z, int g_z, int b_z){
    if ((x >= bmiV3->width) || (y >= bmiV3->height) || (x < 0) || (y < 0) || (l < 0) || (w < 0))
        printf("ERROR!! Wrong coordinates or data. The start file will be written!\n");
    else if ((r < 0) || (r > 255) || (g < 0) || (g > 255) || (b < 0) || (b > 255) || (r_z < 0) || (r_z > 255) || (g_z < 0) || (g_z > 255) || (b_z < 0) || (b_z > 255)){
        printf("ERROR!! Wrong component. The start file will be written!\n");
    }
    else if (w > l / 2){
        printf("ERROR!! Width > side. The start file will be written!\n");
    }
    else{
        y = (int)bmiV3->height - 1 - y;
        for (int p = 0; p < w; p++){
            if (y >= p){
                for (int v = 0; v < l; v++){
                    if (x + v < bmiV3->width){
                        image[y - p][x + v].r = r;
                        image[y - p][x + v].g = g;
                        image[y - p][x + v].b = b;
                    }
                }
            }
        }
        for(int f = 0; f < (l - 2 * w); f++){
            if (y >= f + w){
                for(int k = 0; k < w; k++){
                    if (x + k < bmiV3->width) {
                        image[y - w - f][x + k].r = r;
                        image[y - w - f][x + k].g = g;
                        image[y - w - f][x + k].b = b;
                    }
                    if (x + l - k - 1 < bmiV3->width){
                        image[y - w - f][x + l - k - 1].r = r;
                        image[y - w - f][x + l - k - 1].g = g;
                        image[y - w - f][x + l - k - 1].b = b;
                    }
                }
                for(int a = 0; a < l - 2 * w; a++){
                    if (x + w + a < bmiV3->width){
                        image[y - w - f][x + w + a].r = r_z;
                        image[y - w - f][x + w + a].g = g_z;
                        image[y - w - f][x + w + a].b = b_z;
                    }
                }
            }
        }
        for (int p = 0; p < w; p++){
            if (y >= l - w + p){
                for (int v = 0; v < l; v++){
                    if (x + v < bmiV3->width){
                        image[y - (l - w + p)][x + v].r = r;
                        image[y - (l - w + p)][x + v].g = g;
                        image[y - (l - w + p)][x + v].b = b;
                    }
                }
            }
        }
        int size = (int)(w / sqrt(2));
        for (int j = w; j < l - w; j++){
            for(int m = 0; m < size + 1; m++){
                if ((y >= j + m) && (x + j < bmiV3->width)){
                    image[y - j - m][x + j].r = r;
                    image[y - j - m][x + j].g = g;
                    image[y - j - m][x + j].b = b;
                }
                if ((y >= j - m) && (x + j < bmiV3->width)){
                    image[y - j + m][x + j].r = r;
                    image[y - j + m][x + j].g = g;
                    image[y - j + m][x + j].b = b;
                }
                if ((y >= j - m) && (x + l - j - 1 < bmiV3->width)){
                    image[y - j + m][x + l - j - 1].r = r;
                    image[y - j + m][x + l - j - 1].g = g;
                    image[y - j + m][x + l - j - 1].b = b;
                }
                if ((y >= j + m) && (x + l - j - 1 < bmiV3->width)){
                    image[y - j - m][x + l - j - 1].r = r;
                    image[y - j - m][x + l - j - 1].g = g;
                    image[y - j - m][x + l - j - 1].b = b;
                }
            }
        }
    }
}