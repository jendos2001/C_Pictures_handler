#include "CircleFromCenter.h"

void CircleFromCenterWithoutFill(BITMAPINFOV3* bmiV3, RGB** image, int x_c, int y_c, int radius, int r, int g, int b, int w) {
    if ((x_c < 0) || (x_c >= bmiV3->width) || (y_c < 0) || (y_c >= bmiV3->height) || (radius < 0) || (w < 0) || ((radius + x_c) >= bmiV3->width) || ((radius + x_c) >= bmiV3->width)) {
        printf("ERROR!! Wrong coordinates or data. The start file will be written!\n");
    } else {
        if (w > radius) {
            printf("ERROR!! Width > Radius. The start file will be written!\n");
        } else {
            if ((r < 0) || (r > 255) || (g < 0) || (g > 255) || (b < 0) || (b > 255)) {
                printf("ERROR!! Wrong components. The start file will be written!\n");
            } else {
                int x1, x2, y1, y2;
                int y_tmp;
                int radius_tmp;
                x1 = x_c - radius;
                x2 = x_c + radius;
                y1 = y_c - radius;
                y2 = y_c + radius;
                for (int o = 0; o < w; o++) {
                    radius_tmp = radius - o;
                    for (int i = 0; i <= abs(y2 - y1) / 2; i++) {
                        if (((int) bmiV3->height - y1 - 1 >= i) && (y1 + i >= 0)) {
                            for (int j = 0; j <= abs(x2 - x1) / 2; j++) {
                                if ((x1 + j < bmiV3->width) && (x1 + j >= 0)) {
                                    if ((((x_c - (x1 + j)) * (x_c - (x1 + j)) + (y_c - (y1 + i)) * (y_c - (y1 + i))) >=
                                         radius_tmp * radius_tmp) && (((x_c - (x1 + j + 1)) * (x_c - (x1 + j + 1)) +
                                                                       (y_c - (y1 + i + 1)) * (y_c - (y1 + i + 1))) <
                                                                      radius_tmp * radius_tmp)) {
                                        y_tmp = (int) bmiV3->height - y1 - 1;
                                        image[y_tmp - i][x1 + j].r = r;
                                        image[y_tmp - i][x1 + j].g = g;
                                        image[y_tmp - i][x1 + j].b = b;
                                    }
                                }
                                if (x2 - j < bmiV3->width) {
                                    if (((((x2 - j) - x_c) * ((x2 - j) - x_c) + (y_c - (y1 + i)) * (y_c - (y1 + i))) >=
                                         radius_tmp * radius_tmp) && (((x2 - j - 1) - x_c) * ((x2 - j - 1) - x_c) +
                                                                      (y_c - (y1 + i + 1)) * (y_c - (y1 + i + 1)) <
                                                                      radius_tmp * radius_tmp)) {
                                        y_tmp = (int) bmiV3->height - y1 - 1;
                                        image[y_tmp - i][x2 - j].r = r;
                                        image[y_tmp - i][x2 - j].g = g;
                                        image[y_tmp - i][x2 - j].b = b;
                                    }
                                }
                            }
                        }
                    }
                    for (int i = 0; i <= abs(y2 - y1) / 2; i++) {
                        if ((y2 >= i) && (y2 < bmiV3->height + i)) {
                            for (int j = 0; j <= abs(x2 - x1) / 2; j++) {
                                if ((x1 + j < bmiV3->width) && (x1 + j >= 0)) {
                                    if ((((x_c - (x1 + j)) * (x_c - (x1 + j)) + ((y2 - i) - y_c) * ((y2 - i) - y_c)) >=
                                         radius_tmp * radius_tmp) && (((x_c - (x1 + j + 1)) * (x_c - (x1 + j + 1)) +
                                                                       ((y2 - i - 1) - y_c) * ((y2 - i - 1) - y_c)) <
                                                                      radius_tmp * radius_tmp)) {
                                        y_tmp = (int) bmiV3->height - y2 - 1;
                                        image[y_tmp + i][x1 + j].r = r;
                                        image[y_tmp + i][x1 + j].g = g;
                                        image[y_tmp + i][x1 + j].b = b;
                                    }
                                }
                                if (x2 - j < bmiV3->width) {
                                    if (((((x2 - j) - x_c) * ((x2 - j) - x_c) + ((y2 - i) - y_c) * ((y2 - i) - y_c)) >=
                                         radius_tmp * radius_tmp) && ((((x2 - j - 1) - x_c) * ((x2 - j - 1) - x_c) +
                                                                       ((y2 - i - 1) - y_c) * ((y2 - i - 1) - y_c)) <
                                                                      radius_tmp * radius_tmp)) {
                                        y_tmp = (int) bmiV3->height - y2 - 1;
                                        image[y_tmp + i][x2 - j].r = r;
                                        image[y_tmp + i][x2 - j].g = g;
                                        image[y_tmp + i][x2 - j].b = b;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


void CircleFromCenterWithFill(BITMAPINFOV3* bmiV3, RGB** image, int x_c, int y_c, int radius, int r, int g, int b, int w, int r_z, int g_z, int b_z) {
    if ((x_c < 0) || (x_c >= bmiV3->width) || (y_c < 0) || (y_c >= bmiV3->height) || (radius < 0) || (w < 0) || ((radius + x_c) >= bmiV3->width) || ((radius + x_c) >= bmiV3->width)) {
        printf("ERROR!! Wrong coordinates or data. The start file will be written!\n");
    } else {
        if (w > radius) {
            printf("ERROR!! Width > Radius. The start file will be written!\n");
        } else {
            if ((r < 0) || (r > 255) || (g < 0) || (g > 255) || (b < 0) || (b > 255) || (r_z < 0) || (r_z > 255) || (g_z < 0) || (g_z > 255) || (b_z < 0) || (b_z > 255)) {
                printf("ERROR!! Wrong components. The start file will be written!\n");
            } else {
                int x1, x2, y1, y2;
                int y_tmp;
                int radius_tmp;
                x1 = x_c - radius;
                x2 = x_c + radius;
                y1 = y_c - radius;
                y2 = y_c + radius;
                for (int o = 0; o < w; o++) {
                    radius_tmp = radius - o;
                    for (int i = 0; i <= abs(y2 - y1) / 2; i++) {
                        if (((int) bmiV3->height - y1 - 1 >= i) && (y1 + i >= 0)) {
                            for (int j = 0; j <= abs(x2 - x1) / 2; j++) {
                                if ((x1 + j < bmiV3->width) && (x1 + j >= 0)) {
                                    if ((((x_c - (x1 + j)) * (x_c - (x1 + j)) + (y_c - (y1 + i)) * (y_c - (y1 + i))) >=
                                         radius_tmp * radius_tmp) && (((x_c - (x1 + j + 1)) * (x_c - (x1 + j + 1)) +
                                                                       (y_c - (y1 + i + 1)) * (y_c - (y1 + i + 1))) <
                                                                      radius_tmp * radius_tmp)) {
                                        y_tmp = (int) bmiV3->height - y1 - 1;
                                        image[y_tmp - i][x1 + j].r = r;
                                        image[y_tmp - i][x1 + j].g = g;
                                        image[y_tmp - i][x1 + j].b = b;
                                    }
                                    if (((x_c - (x1 + j)) * (x_c - (x1 + j)) + (y_c - (y1 + i)) * (y_c - (y1 + i))) <
                                        radius_tmp * radius_tmp) {
                                        image[y_tmp - i][x1 + j].r = r_z;
                                        image[y_tmp - i][x1 + j].g = g_z;
                                        image[y_tmp - i][x1 + j].b = b_z;
                                    }
                                }
                                if (x2 - j < bmiV3->width) {
                                    if (((((x2 - j) - x_c) * ((x2 - j) - x_c) + (y_c - (y1 + i)) * (y_c - (y1 + i))) >=
                                         radius_tmp * radius_tmp) && (((x2 - j - 1) - x_c) * ((x2 - j - 1) - x_c) +
                                                                      (y_c - (y1 + i + 1)) * (y_c - (y1 + i + 1)) <
                                                                      radius_tmp * radius_tmp)) {
                                        y_tmp = (int) bmiV3->height - y1 - 1;
                                        image[y_tmp - i][x2 - j].r = r;
                                        image[y_tmp - i][x2 - j].g = g;
                                        image[y_tmp - i][x2 - j].b = b;
                                    }
                                    if ((((x2 - j) - x_c) * ((x2 - j) - x_c) + (y_c - (y1 + i)) * (y_c - (y1 + i))) <
                                        radius_tmp * radius_tmp) {
                                        image[y_tmp - i][x2 - j].r = r_z;
                                        image[y_tmp - i][x2 - j].g = g_z;
                                        image[y_tmp - i][x2 - j].b = b_z;
                                    }
                                }
                            }
                        }
                    }
                    for (int i = 0; i <= abs(y2 - y1) / 2; i++) {
                        if ((y2 >= i) && (y2 < bmiV3->height + i)) {
                            for (int j = 0; j <= abs(x2 - x1) / 2; j++) {
                                if ((x1 + j < bmiV3->width) && (x1 + j >= 0)) {
                                    if ((((x_c - (x1 + j)) * (x_c - (x1 + j)) + ((y2 - i) - y_c) * ((y2 - i) - y_c)) >=
                                         radius_tmp * radius_tmp) && (((x_c - (x1 + j + 1)) * (x_c - (x1 + j + 1)) +
                                                                       ((y2 - i - 1) - y_c) * ((y2 - i - 1) - y_c)) <
                                                                      radius_tmp * radius_tmp)) {
                                        y_tmp = (int) bmiV3->height - y2 - 1;
                                        image[y_tmp + i][x1 + j].r = r;
                                        image[y_tmp + i][x1 + j].g = g;
                                        image[y_tmp + i][x1 + j].b = b;
                                    }
                                    if (((x_c - (x1 + j)) * (x_c - (x1 + j)) + ((y2 - i) - y_c) * ((y2 - i) - y_c)) <
                                        radius_tmp * radius_tmp) {
                                        image[y_tmp + i][x1 + j].r = r_z;
                                        image[y_tmp + i][x1 + j].g = g_z;
                                        image[y_tmp + i][x1 + j].b = b_z;
                                    }
                                }
                                if (x2 - j < bmiV3->width) {
                                    if (((((x2 - j) - x_c) * ((x2 - j) - x_c) + ((y2 - i) - y_c) * ((y2 - i) - y_c)) >=
                                         radius_tmp * radius_tmp) && ((((x2 - j - 1) - x_c) * ((x2 - j - 1) - x_c) +
                                                                       ((y2 - i - 1) - y_c) * ((y2 - i - 1) - y_c)) <
                                                                      radius_tmp * radius_tmp)) {
                                        y_tmp = (int) bmiV3->height - y2 - 1;
                                        image[y_tmp + i][x2 - j].r = r;
                                        image[y_tmp + i][x2 - j].g = g;
                                        image[y_tmp + i][x2 - j].b = b;
                                    }
                                    if ((((x2 - j) - x_c) * ((x2 - j) - x_c) + ((y2 - i) - y_c) * ((y2 - i) - y_c)) <
                                        radius_tmp * radius_tmp) {
                                        image[y_tmp + i][x2 - j].r = r_z;
                                        image[y_tmp + i][x2 - j].g = g_z;
                                        image[y_tmp + i][x2 - j].b = b_z;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}