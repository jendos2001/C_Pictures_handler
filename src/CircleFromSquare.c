#include "CircleFromSquare.h"

void CircleFromSquareWithoutFill(BITMAPINFOV3* bmiV3, RGB** image ,int x1, int y1, int x2, int y2, int r, int g, int b, int d) {
    if ((x1 < 0) || (x1 >= bmiV3->width) || (y1 < 0) || (y1 >= bmiV3->height) || (x2 < 0) || (x2 >= bmiV3->width) ||
        (y2 < 0) || (y2 >= bmiV3->height) || (x2 < x1) || (y2 < y1) || (d < 0)) {
        printf("ERROR!! Wrong coordinates or data. The start file will be written!\n");
    } else {
        if (d > (x2 - x1) / 2) {
            printf("ERROR!! Width > Radius. The start file will be written!\n");
        } else {
            if ((r < 0) || (r > 255) || (g < 0) || (g > 255) || (b < 0) || (b > 255)) {
                printf("ERROR!! Wrong components. The start file will be written!\n");
            } else {
                if ((x2 - x1) != (y2 - y1)) {
                    printf("ERROR!! Don't square. The start file will be written!\n");
                } else {
                    int x_c, y_c;
                    int radius;
                    int y_tmp;
                    x_c = (int) ((x1 + x2) / 2);
                    y_c = (int) ((y1 + y2) / 2);
                    for (int o = 0; o < d; o++) {
                        radius = (int) ((x2 - x1) / 2) - o;
                        for (int i = 0; i <= abs(y2 - y1) / 2; i++) {
                            if ((int) bmiV3->height - y1 - 1 >= i) {
                                for (int j = 0; j <= abs(x2 - x1) / 2; j++) {
                                    if (x1 + j < bmiV3->width) {
                                        if ((((x_c - (x1 + j)) * (x_c - (x1 + j)) +
                                              (y_c - (y1 + i)) * (y_c - (y1 + i))) >=
                                             radius * radius) && (((x_c - (x1 + j + 1)) * (x_c - (x1 + j + 1)) +
                                                                   (y_c - (y1 + i + 1)) * (y_c - (y1 + i + 1))) <
                                                                  radius * radius)) {
                                            y_tmp = (int) bmiV3->height - y1 - 1;
                                            image[y_tmp - i][x1 + j].r = r;
                                            image[y_tmp - i][x1 + j].g = g;
                                            image[y_tmp - i][x1 + j].b = b;
                                        }
                                    }
                                    if (x2 - j < bmiV3->width) {
                                        if (((((x2 - j) - x_c) * ((x2 - j) - x_c) +
                                              (y_c - (y1 + i)) * (y_c - (y1 + i))) >=
                                             radius * radius) && (((x2 - j - 1) - x_c) * ((x2 - j - 1) - x_c) +
                                                                  (y_c - (y1 + i + 1)) * (y_c - (y1 + i + 1)) <
                                                                  radius * radius)) {
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
                                    if (x1 + j < bmiV3->width) {
                                        if ((((x_c - (x1 + j)) * (x_c - (x1 + j)) +
                                              ((y2 - i) - y_c) * ((y2 - i) - y_c)) >=
                                             radius * radius) && (((x_c - (x1 + j + 1)) * (x_c - (x1 + j + 1)) +
                                                                   ((y2 - i - 1) - y_c) * ((y2 - i - 1) - y_c)) <
                                                                  radius * radius)) {
                                            y_tmp = (int) bmiV3->height - y2 - 1;
                                            image[y_tmp + i][x1 + j].r = r;
                                            image[y_tmp + i][x1 + j].g = g;
                                            image[y_tmp + i][x1 + j].b = b;
                                        }
                                    }
                                    if (x2 - j < bmiV3->width) {
                                        if (((((x2 - j) - x_c) * ((x2 - j) - x_c) +
                                              ((y2 - i) - y_c) * ((y2 - i) - y_c)) >=
                                             radius * radius) && ((((x2 - j - 1) - x_c) * ((x2 - j - 1) - x_c) +
                                                                   ((y2 - i - 1) - y_c) * ((y2 - i - 1) - y_c)) <
                                                                  radius * radius)) {
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
}

void CircleFromSquareWithFill(BITMAPINFOV3 *bmiV3, RGB **image, int x1, int y1, int x2, int y2, int r, int g, int b,
                              int d, int r_z, int g_z, int b_z) {
    if ((x1 < 0) || (x1 >= bmiV3->width) || (y1 < 0) || (y1 >= bmiV3->height) || (x2 < 0) || (x2 >= bmiV3->width) ||
        (y2 < 0) || (y2 >= bmiV3->height) || (x2 < x1) || (y2 < y1) || (d < 0)) {
        printf("ERROR!! Wrong coordinates or data. The start file will be written!\n");
    } else {
        if (d > (x2 - x1) / 2) {
            printf("ERROR!! Width > Radius. The start file will be written!\n");
        } else {
            if ((r < 0) || (r > 255) || (g < 0) || (g > 255) || (b < 0) || (b > 255) || (r_z < 0) || (r_z > 255) ||
                (g_z < 0) || (g_z > 255) || (b_z < 0) || (b_z > 255)) {
                printf("ERROR!! Wrong components. The start file will be written!\n");
            } else {
                if ((x2 - x1) != (y2 - y1)) {
                    printf("ERROR!! Don't square. The start file will be written!\n");
                } else {
                    int x_c, y_c;
                    int radius;
                    int y_tmp;
                    x_c = (int) ((x1 + x2) / 2);
                    y_c = (int) ((y1 + y2) / 2);
                    for (int o = 0; o < d; o++) {
                        radius = (int) ((x2 - x1) / 2) - o;
                        for (int i = 0; i <= abs(y2 - y1) / 2; i++) {
                            if ((int) bmiV3->height - y1 - 1 >= i) {
                                for (int j = 0; j <= abs(x2 - x1) / 2; j++) {
                                    if (x1 + j < bmiV3->width) {
                                        if ((((x_c - (x1 + j)) * (x_c - (x1 + j)) +
                                              (y_c - (y1 + i)) * (y_c - (y1 + i))) >=
                                             radius * radius) && (((x_c - (x1 + j + 1)) * (x_c - (x1 + j + 1)) +
                                                                   (y_c - (y1 + i + 1)) * (y_c - (y1 + i + 1))) <
                                                                  radius * radius)) {
                                            y_tmp = (int) bmiV3->height - y1 - 1;
                                            image[y_tmp - i][x1 + j].r = r;
                                            image[y_tmp - i][x1 + j].g = g;
                                            image[y_tmp - i][x1 + j].b = b;
                                        }
                                        if (((x_c - (x1 + j)) * (x_c - (x1 + j)) +
                                             (y_c - (y1 + i)) * (y_c - (y1 + i))) <
                                            radius * radius) {
                                            image[y_tmp - i][x1 + j].r = r_z;
                                            image[y_tmp - i][x1 + j].g = g_z;
                                            image[y_tmp - i][x1 + j].b = b_z;
                                        }
                                    }
                                    if (x2 - j < bmiV3->width) {
                                        if (((((x2 - j) - x_c) * ((x2 - j) - x_c) +
                                              (y_c - (y1 + i)) * (y_c - (y1 + i))) >=
                                             radius * radius) && (((x2 - j - 1) - x_c) * ((x2 - j - 1) - x_c) +
                                                                  (y_c - (y1 + i + 1)) * (y_c - (y1 + i + 1)) <
                                                                  radius * radius)) {
                                            y_tmp = (int) bmiV3->height - y1 - 1;
                                            image[y_tmp - i][x2 - j].r = r;
                                            image[y_tmp - i][x2 - j].g = g;
                                            image[y_tmp - i][x2 - j].b = b;
                                        }
                                        if ((((x2 - j) - x_c) * ((x2 - j) - x_c) +
                                             (y_c - (y1 + i)) * (y_c - (y1 + i))) <
                                            radius * radius) {
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
                                    if (x1 + j < bmiV3->width) {
                                        if ((((x_c - (x1 + j)) * (x_c - (x1 + j)) +
                                              ((y2 - i) - y_c) * ((y2 - i) - y_c)) >=
                                             radius * radius) && (((x_c - (x1 + j + 1)) * (x_c - (x1 + j + 1)) +
                                                                   ((y2 - i - 1) - y_c) * ((y2 - i - 1) - y_c)) <
                                                                  radius * radius)) {
                                            y_tmp = (int) bmiV3->height - y2 - 1;
                                            image[y_tmp + i][x1 + j].r = r;
                                            image[y_tmp + i][x1 + j].g = g;
                                            image[y_tmp + i][x1 + j].b = b;
                                        }
                                        if (((x_c - (x1 + j)) * (x_c - (x1 + j)) +
                                             ((y2 - i) - y_c) * ((y2 - i) - y_c)) <
                                            radius * radius) {
                                            image[y_tmp + i][x1 + j].r = r_z;
                                            image[y_tmp + i][x1 + j].g = g_z;
                                            image[y_tmp + i][x1 + j].b = b_z;
                                        }
                                    }
                                    if (x2 - j < bmiV3->width) {
                                        if (((((x2 - j) - x_c) * ((x2 - j) - x_c) +
                                              ((y2 - i) - y_c) * ((y2 - i) - y_c)) >=
                                             radius * radius) && ((((x2 - j - 1) - x_c) * ((x2 - j - 1) - x_c) +
                                                                   ((y2 - i - 1) - y_c) * ((y2 - i - 1) - y_c)) <
                                                                  radius * radius)) {
                                            y_tmp = (int) bmiV3->height - y2 - 1;
                                            image[y_tmp + i][x2 - j].r = r;
                                            image[y_tmp + i][x2 - j].g = g;
                                            image[y_tmp + i][x2 - j].b = b;
                                        }
                                        if ((((x2 - j) - x_c) * ((x2 - j) - x_c) +
                                             ((y2 - i) - y_c) * ((y2 - i) - y_c)) <
                                            radius * radius) {
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
}
