#include "TurnImage.h"

int TurnImage(BITMAPFILEHEADER* bmfh, BITMAPINFOV3* bmiV3, RGB** image, int x1, int y1, int x2, int y2, int alpha, char* outputfile){
    if ((x1 >= bmiV3->width) || (y1 >= bmiV3->height) || (x1 < 0) || (y1 < 0) || (x2 < 0) || (x2 >= bmiV3->width) || (y2 < 0) || (y2 >= bmiV3->height) || (x2 < x1) || (y2 < y1))
        printf("ERROR!! Wrong coordinates or data. The start file will be written!\n");
    else if ((alpha != 90) && (alpha != 180) && (alpha != 270))
        printf("ERROR!! Wrong angle. The start file will be written!\n");
    else {
        int x_c, y_c;
        int cur;
        int start_x;
        unsigned int width_tmp;
        RGB *tmp;
        RGB **tmp_image;
        if (((x1 == 0) && (x2 == bmiV3->width - 1) && (y1 == 0) && (y2 == bmiV3->height - 1)) &&
            ((alpha == 90) || (alpha == 270))) {
            tmp_image = malloc(bmiV3->width * sizeof(RGB *));
            for (int i = 0; i < abs(x2 - x1) + 1; i++)
                tmp_image[i] = malloc(bmiV3->height * sizeof(RGB));
            y2 = (int) bmiV3->height - 1 - y2;
            y1 = (int) bmiV3->height - 1 - y1;
            if (alpha == 90) {
                for (int i = 0; i < bmiV3->width; i++) {
                    for (int j = 0; j < bmiV3->height; j++) {
                        tmp_image[i][j].r = image[y2 + j][x2 - i].r;
                        tmp_image[i][j].g = image[y2 + j][x2 - i].g;
                        tmp_image[i][j].b = image[y2 + j][x2 - i].b;
                    }
                }
            } else {
                for (int i = 0; i < abs(x2 - x1) + 1; i++) {
                    for (int j = 0; j < abs(y2 - y1) + 1; j++) {
                        tmp_image[i][j].r = image[y1 - j][x1 + i].r;
                        tmp_image[i][j].g = image[y1 - j][x1 + i].g;
                        tmp_image[i][j].b = image[y1 - j][x1 + i].b;
                    }
                }
            }
            width_tmp = bmiV3->width;
            bmiV3->width = bmiV3->height;
            bmiV3->height = width_tmp;
            WriteImage(bmfh, bmiV3, tmp_image, outputfile);
            for (int i = 0; i < abs(x2 - x1) + 1; i++)
                free(tmp_image[i]);
            free(tmp_image);
            return 1;
        } else {
            if ((alpha == 90) || (alpha == 270)) {
                x_c = (int) ((x2 + x1) / 2);
                y_c = (int) ((y2 + y1) / 2);
                if ((x2 - x1) % 2 == 0)
                    cur = (int) y_c - (int) ((x2 - x1) / 2);
                else
                    cur = (int) y_c - (int) ((x2 - x1 + 1) / 2);
                cur = (int) bmiV3->height - 1 - cur;
                if (abs(y2 - y1) % 2 == 0) {
                    start_x = x_c - (int) (abs(y2 - y1) / 2);
                } else
                    start_x = x_c - (int) (abs(y2 - y1 + 1) / 2);
                y2 = (int) bmiV3->height - 1 - y2;
                y1 = (int) bmiV3->height - 1 - y1;
                tmp_image = malloc((abs(x2 - x1) + 1) * sizeof(RGB *));
                for (int i = 0; i < abs(x2 - x1) + 1; i++)
                    tmp_image[i] = malloc((abs(y2 - y1) + 1) * sizeof(RGB));
                if (alpha == 90) {
                    for (int i = 0; i < abs(x2 - x1) + 1; i++) {
                        for (int j = 0; j < abs(y2 - y1) + 1; j++) {
                            tmp_image[i][j].r = image[y2 + j][x1 + i].r;
                            tmp_image[i][j].g = image[y2 + j][x1 + i].g;
                            tmp_image[i][j].b = image[y2 + j][x1 + i].b;
                        }
                    }
                    if ((x2 - x1) > abs(y2 - y1)) {
                        for (int i = 0; i < (x2 - x1 - abs(y2 - y1)) / 2; i++) {
                            for (int j = 0; j <= abs(y2 - y1); j++) {
                                image[y1 - j][x_c + ((int) (abs(y2 - y1) / 2) + i)].r = 255;
                                image[y1 - j][x_c + ((int) (abs(y2 - y1) / 2) + i)].g = 255;
                                image[y1 - j][x_c + ((int) (abs(y2 - y1) / 2) + i)].b = 255;
                                image[y1 - j][x_c - ((int) (abs(y2 - y1) / 2) + i)].r = 255;
                                image[y1 - j][x_c - ((int) (abs(y2 - y1) / 2) + i)].g = 255;
                                image[y1 - j][x_c - ((int) (abs(y2 - y1) / 2) + i)].b = 255;
                            }
                        }
                    } else if ((x2 - x1) < abs(y2 - y1)) {
                        for (int i = 0; i <= (abs(y2 - y1) - (x2 - x1)) / 2; i++) {
                            for (int j = 0; j <= abs(x2 - x1); j++) {
                                image[bmiV3->height - y_c - 1 + ((int) (abs(x2 - x1) / 2) + i)][x1 + j].r = 255;
                                image[bmiV3->height - y_c - 1 + ((int) (abs(x2 - x1) / 2) + i)][x1 + j].g = 255;
                                image[bmiV3->height - y_c - 1 + ((int) (abs(x2 - x1) / 2) + i)][x1 + j].b = 255;
                                image[bmiV3->height - y_c - 1 - ((int) (abs(x2 - x1) / 2) + i)][x1 + j].r = 255;
                                image[bmiV3->height - y_c - 1 - ((int) (abs(x2 - x1) / 2) + i)][x1 + j].g = 255;
                                image[bmiV3->height - y_c - 1 - ((int) (abs(x2 - x1) / 2) + i)][x1 + j].b = 255;
                            }
                        }
                    }

                } else {
                    for (int i = 0; i < abs(x2 - x1) + 1; i++) {
                        for (int j = 0; j < abs(y2 - y1) + 1; j++) {
                            tmp_image[i][j].r = image[y1 - j][x2 - i].r;
                            tmp_image[i][j].g = image[y1 - j][x2 - i].g;
                            tmp_image[i][j].b = image[y1 - j][x2 - i].b;
                        }
                    }
                    if ((x2 - x1) > abs(y2 - y1)) {
                        for (int i = 0; i < (x2 - x1 - abs(y2 - y1)) / 2; i++) {
                            for (int j = 0; j <= abs(y2 - y1); j++) {
                                image[y1 - j][x_c + ((int) (abs(y2 - y1) / 2) + i)].r = 255;
                                image[y1 - j][x_c + ((int) (abs(y2 - y1) / 2) + i)].g = 255;
                                image[y1 - j][x_c + ((int) (abs(y2 - y1) / 2) + i)].b = 255;
                                image[y1 - j][x_c - ((int) (abs(y2 - y1) / 2) + i)].r = 255;
                                image[y1 - j][x_c - ((int) (abs(y2 - y1) / 2) + i)].g = 255;
                                image[y1 - j][x_c - ((int) (abs(y2 - y1) / 2) + i)].b = 255;
                            }
                        }
                    } else if ((x2 - x1) < abs(y2 - y1)) {
                        for (int i = 0; i <= (abs(y2 - y1) - (x2 - x1)) / 2; i++) {
                            for (int j = 0; j <= abs(x2 - x1); j++) {
                                image[bmiV3->height - y_c - 1 + ((int) (abs(x2 - x1) / 2) + i)][x1 + j].r = 255;
                                image[bmiV3->height - y_c - 1 + ((int) (abs(x2 - x1) / 2) + i)][x1 + j].g = 255;
                                image[bmiV3->height - y_c - 1 + ((int) (abs(x2 - x1) / 2) + i)][x1 + j].b = 255;
                                image[bmiV3->height - y_c - 1 - ((int) (abs(x2 - x1) / 2) + i)][x1 + j].r = 255;
                                image[bmiV3->height - y_c - 1 - ((int) (abs(x2 - x1) / 2) + i)][x1 + j].g = 255;
                                image[bmiV3->height - y_c - 1 - ((int) (abs(x2 - x1) / 2) + i)][x1 + j].b = 255;
                            }
                        }
                    }
                }
                for (int i = 0; i <= (x2 - x1); i++) {
                    if ((cur >= i) && (cur - i < bmiV3->height)) {
                        for (int j = 0; j <= abs(y2 - y1); j++) {
                            if ((start_x + j < bmiV3->width) && (start_x + j >= 0)) {
                                image[cur - i][start_x + j].r = tmp_image[i][j].r;
                                image[cur - i][start_x + j].g = tmp_image[i][j].g;
                                image[cur - i][start_x + j].b = tmp_image[i][j].b;
                            }
                        }
                    }
                }
                for (int i = 0; i < abs(x2 - x1) + 1; i++)
                    free(tmp_image[i]);
                free(tmp_image);
            } else {
                tmp = malloc(1 * sizeof(RGB));
                y2 = (int) bmiV3->height - 1 - y2;
                y1 = (int) bmiV3->height - 1 - y1;
                for (int i = 0; i < (abs(y2 - y1) + 1) / 2; i++) {
                    for (int j = 0; j < abs(x2 - x1) + 1; j++) {
                        tmp->r = image[y1 - i][x1 + j].r;
                        tmp->g = image[y1 - i][x1 + j].g;
                        tmp->b = image[y1 - i][x1 + j].b;
                        image[y1 - i][x1 + j].r = image[y2 + i][x2 - j].r;
                        image[y1 - i][x1 + j].g = image[y2 + i][x2 - j].g;
                        image[y1 - i][x1 + j].b = image[y2 + i][x2 - j].b;
                        image[y2 + i][x2 - j].r = tmp->r;
                        image[y2 + i][x2 - j].g = tmp->g;
                        image[y2 + i][x2 - j].b = tmp->b;
                    }
                }
                if (abs(y2 - y1) % 2 == 0) {
                    for (int i = 0; i < (abs(x2 - x1) + 1) / 2; i++) {
                        tmp->r = image[y1 - abs(y2 - y1) / 2][x1 + i].r;
                        tmp->g = image[y1 - abs(y2 - y1) / 2][x1 + i].g;
                        tmp->b = image[y1 - abs(y2 - y1) / 2][x1 + i].b;
                        image[y1 - abs(y2 - y1) / 2][x1 + i].r = image[y1 - abs(y2 - y1) / 2][x2 - i].r;
                        image[y1 - abs(y2 - y1) / 2][x1 + i].g = image[y1 - abs(y2 - y1) / 2][x2 - i].g;
                        image[y1 - abs(y2 - y1) / 2][x1 + i].b = image[y1 - abs(y2 - y1) / 2][x2 - i].b;
                        image[y1 - abs(y2 - y1) / 2][x2 - i].r = tmp->r;
                        image[y1 - abs(y2 - y1) / 2][x2 - i].g = tmp->g;
                        image[y1 - abs(y2 - y1) / 2][x2 - i].b = tmp->b;
                    }
                }
                free(tmp);
            }
        }
    }
    return 0;
}