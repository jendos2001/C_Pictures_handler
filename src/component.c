#include "component.h"

void component(BITMAPINFOV3* bmiV3, RGB** image, char* s, int component_value){
    if ((component_value < 0) || (component_value > 255)){
        printf("ERROR!! Wrong components. The start file will be written!\n");
    }
    else {
        if (strcmp(s, "Red") == 0){
            for (int i = 0; i < bmiV3->height; i++)
                for (int j = 0; j < bmiV3->width; j++)
                    image[i][j].r = component_value;
        }
        else{
            if (strcmp(s, "Green") == 0){
                for (int i = 0; i < bmiV3->height; i++)
                    for (int j = 0; j < bmiV3->width; j++)
                        image[i][j].g = component_value;
            }
            else{
                if (strcmp(s, "Blue") == 0){
                    for (int i = 0; i < bmiV3->height; i++)
                        for (int j = 0; j < bmiV3->width; j++)
                            image[i][j].b = component_value;
                }
                else{
                    printf("ERROR!! Wrong Color. The start file will be written!\n");
                }
            }
        }
    }
}