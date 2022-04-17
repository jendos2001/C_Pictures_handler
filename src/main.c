#include "structures.h"
#include "libraries.h"
#include "component.h"
#include "CircleFromSquare.h"
#include "CircleFromCenter.h"
#include "Square.h"
#include "TurnImage.h"
#include "WriteImage.h"
#include "Swap.h"
#include "ReadImage.h"
#include "FreeMemory.h"
#include "help.h"
#include "information.h"

int main(int argc, char* argv[]){
    int k;
    char inputfile[300];
    char outputfile[300];
    char *comp = calloc(100, sizeof(char));
    char find[11] = "1234567890";
    struct Commands cmd;
    cmd.n = 0;
    cmd.x1 = -1;
    cmd.y1 = -1;
    cmd.x2 = -1;
    cmd.y2 = -1;
    cmd.l = -1;
    cmd.w = -1;
    cmd.red = -1;
    cmd.green = -1;
    cmd.blue = -1;
    cmd.x_c = -1;
    cmd.y_c = -1;
    cmd.fill = 0;
    cmd.red_fill = -1;
    cmd.green_fill = -1;
    cmd.blue_fill = -1;
    cmd.alpha = -1;
    cmd.radius = -1;
    cmd.component_value = -1;
    cmd.option = -1;
    cmd.error = -1;
    cmd.output = 0;
    int opt;
    int longInd;
    char* optStr = "r:g:b:o:sftchi";
    struct option longOpts[]={
            {"Information", no_argument, NULL, 'i'},
            {"Help", no_argument, NULL, 'h'},
            {"InputFile", no_argument, NULL, 0},
            {"OutputFile", no_argument, NULL, 0},
            {"Square", no_argument, NULL, 's'},
            {"X_UpLeft", required_argument, NULL, 0},
            {"Y_UpLeft", required_argument, NULL, 0},
            {"X_DownRight", required_argument, NULL, 0},
            {"Y_DownRight", required_argument, NULL, 0},
            {"Length", required_argument, NULL, 0},
            {"Width", required_argument, NULL, 0},
            {"Red", required_argument, NULL, 'r'},
            {"Green", required_argument, NULL, 'g'},
            {"Blue", required_argument, NULL, 'b'},
            {"Fill", no_argument, NULL, 0},
            {"Red_Fill", required_argument, NULL, 0},
            {"Green_Fill", required_argument, NULL, 0},
            {"Blue_Fill", required_argument, NULL, 0},
            {"Filter", no_argument, NULL, 'f'},
            {"Component", required_argument, NULL, 0},
            {"Component_Value", required_argument, NULL, 0},
            {"Turn_Image", no_argument, NULL, 't'},
            {"Alpha", required_argument, NULL, 0},
            {"Circle", no_argument, NULL, 'c'},
            {"Option", required_argument, NULL, 'o'},
            {"X_Center", required_argument, NULL, 0},
            {"Y_Center", required_argument, NULL, 0},
            {"Radius", required_argument, NULL, 0},
            { NULL, 0, NULL, 0}
    };
    opt = getopt_long(argc, argv, optStr, longOpts, &longInd);
    while(opt != -1){
        switch (opt) {
            case 'r':
                k = 0;
                for(int i = 0; i < strlen(argv[optind - 1]); i++){
                    if(strchr(find, argv[optind - 1][i]) == NULL){
                        k += 1;
                    }
                }
                if (k == 0)
                    cmd.red = atoi(argv[optind - 1]);
                break;
            case 'g':
                k = 0;
                for(int i = 0; i < strlen(argv[optind - 1]); i++){
                    if(strchr(find, argv[optind - 1][i]) == NULL){
                        k += 1;
                    }
                }
                if (k == 0)
                    cmd.green = atoi(argv[optind - 1]);
                break;
            case 'b':
                k = 0;
                for(int i = 0; i < strlen(argv[optind - 1]); i++){
                    if(strchr(find, argv[optind - 1][i]) == NULL){
                        k += 1;
                    }
                }
                if (k == 0)
                    cmd.blue = atoi(argv[optind - 1]);
                break;
            case 'o':
                k = 0;
                for(int i = 0; i < strlen(argv[optind - 1]); i++){
                    if(strchr(find, argv[optind - 1][i]) == NULL){
                        k += 1;
                    }
                }
                if (k == 0)
                    cmd.option = atoi(argv[optind - 1]);
                break;
            case 's':
                cmd.n = 1;
                cmd.error += 1;
                break;
            case 'f':
                cmd.n = 2;
                cmd.error += 1;
                break;
            case 't':
                cmd.n = 3;
                cmd.error += 1;
                break;
            case 'c':
                cmd.n = 4;
                cmd.error += 1;
                break;
            case 'h':
                cmd.n = 5;
                cmd.error += 1;
                break;
            case 'i':
                cmd.n = 6;
                cmd.error += 1;
                break;
            case 0:
                if(strcmp("InputFile", longOpts[longInd].name)==0){
                    strcpy(inputfile, argv[optind]);
                }
                if(strcmp("OutputFile", longOpts[longInd].name)==0){
                    cmd.output = 1;
                    strcpy(outputfile, argv[optind]);
                }
                if(strcmp("Fill", longOpts[longInd].name) == 0){
                    cmd.fill = 1;
                }
                if(strcmp("Component", longOpts[longInd].name) == 0){
                    strcpy(comp, argv[optind - 1]);
                    comp[strlen(argv[optind - 1])] = '\0';
                }
                if(strcmp("Radius", longOpts[longInd].name) == 0){
                    k = 0;
                    for(int i = 0; i < strlen(argv[optind - 1]); i++){
                        if(strchr(find, argv[optind - 1][i]) == NULL){
                            k += 1;
                        }
                    }
                    if (k == 0)
                        cmd.radius = atoi(argv[optind - 1]);
                }
                if(strcmp("Y_Center", longOpts[longInd].name)==0){
                    k = 0;
                    for(int i = 0; i < strlen(argv[optind - 1]); i++){
                        if(strchr(find, argv[optind - 1][i]) == NULL){
                            k += 1;
                        }
                    }
                    if (k == 0)
                        cmd.y_c = atoi(argv[optind - 1]);
                }
                if(strcmp("X_Center", longOpts[longInd].name)==0){
                    k = 0;
                    for(int i = 0; i < strlen(argv[optind - 1]); i++){
                        if(strchr(find, argv[optind - 1][i]) == NULL){
                            k += 1;
                        }
                    }
                    if (k == 0)
                        cmd.x_c = atoi(argv[optind - 1]);
                }
                if(strcmp("Alpha", longOpts[longInd].name)==0){
                    k = 0;
                    for(int i = 0; i < strlen(argv[optind - 1]); i++){
                        if(strchr(find, argv[optind - 1][i]) == NULL){
                            k += 1;
                        }
                    }
                    if (k == 0)
                        cmd.alpha = atoi(argv[optind - 1]);
                }
                if(strcmp("Component_Value", longOpts[longInd].name)==0){
                    k = 0;
                    for(int i = 0; i < strlen(argv[optind - 1]); i++){
                        if(strchr(find, argv[optind - 1][i]) == NULL){
                            k += 1;
                        }
                    }
                    if (k == 0)
                        cmd.component_value = atoi(argv[optind - 1]);
                }
                if(strcmp("X_UpLeft", longOpts[longInd].name)==0){
                    k = 0;
                    for(int i = 0; i < strlen(argv[optind - 1]); i++){
                        if(strchr(find, argv[optind - 1][i]) == NULL){
                            k += 1;
                        }
                    }
                    if (k == 0)
                        cmd.x1 = atoi(argv[optind - 1]);
                }
                if(strcmp("X_DownRight", longOpts[longInd].name)==0){
                    k = 0;
                    for(int i = 0; i < strlen(argv[optind - 1]); i++){
                        if(strchr(find, argv[optind - 1][i]) == NULL){
                            k += 1;
                        }
                    }
                    if (k == 0)
                        cmd.x2 = atoi(argv[optind - 1]);
                }
                if(strcmp("Y_DownRight", longOpts[longInd].name)==0){
                    k = 0;
                    for(int i = 0; i < strlen(argv[optind - 1]); i++){
                        if(strchr(find, argv[optind - 1][i]) == NULL){
                            k += 1;
                        }
                    }
                    if (k == 0)
                        cmd.y2 = atoi(argv[optind - 1]);
                }
                if(strcmp("Y_UpLeft", longOpts[longInd].name)==0){
                    k = 0;
                    for(int i = 0; i < strlen(argv[optind - 1]); i++){
                        if(strchr(find, argv[optind - 1][i]) == NULL){
                            k += 1;
                        }
                    }
                    if (k == 0)
                        cmd.y1 = atoi(argv[optind - 1]);
                }
                if(strcmp("Width", longOpts[longInd].name)==0){
                    k = 0;
                    for(int i = 0; i < strlen(argv[optind - 1]); i++){
                        if(strchr(find, argv[optind - 1][i]) == NULL){
                            k += 1;
                        }
                    }
                    if (k == 0)
                        cmd.w = atoi(argv[optind - 1]);
                }
                if(strcmp("Length", longOpts[longInd].name)==0){
                    k = 0;
                    for(int i = 0; i < strlen(argv[optind - 1]); i++){
                        if(strchr(find, argv[optind - 1][i]) == NULL){
                            k += 1;
                        }
                    }
                    if (k == 0)
                        cmd.l = atoi(argv[optind - 1]);
                }
                if(strcmp("Red_Fill", longOpts[longInd].name)==0){
                    k = 0;
                    for(int i = 0; i < strlen(argv[optind - 1]); i++){
                        if(strchr(find, argv[optind - 1][i]) == NULL){
                            k += 1;
                        }
                    }
                    if (k == 0)
                        cmd.red_fill = atoi(argv[optind - 1]);
                }
                if(strcmp("Green_Fill", longOpts[longInd].name)==0){
                    k = 0;
                    for(int i = 0; i < strlen(argv[optind - 1]); i++){
                        if(strchr(find, argv[optind - 1][i]) == NULL){
                            k += 1;
                        }
                    }
                    if (k == 0)
                        cmd.green_fill = atoi(argv[optind - 1]);
                }
                if(strcmp("Blue_Fill", longOpts[longInd].name)==0){
                    k = 0;
                    for(int i = 0; i < strlen(argv[optind - 1]); i++){
                        if(strchr(find, argv[optind - 1][i]) == NULL){
                            k += 1;
                        }
                    }
                    if (k == 0)
                        cmd.blue_fill = atoi(argv[optind - 1]);
                }

                break;
        }
        opt = getopt_long(argc, argv, optStr, longOpts, &longInd);
    }
    if(argv[1]==NULL){
        printf("You did not enter any arguments!\n");
        help();
        return 0;
    }
    if (cmd.error == -1){
        printf("You did not call any function!\n");
        help();
        return 0;
    }
    else if(cmd.error != 0){
        printf("You called more than one function!\n");
        help();
        return 0;
    }
    if ((cmd.output == 0) && !((cmd.n == 5) || (cmd.n == 6))){
        printf("You did not enter an output file name!\n");
        help();
        return 0;
    }
    else if (cmd.n == 5){
        help();
        return 0;
    }
    FILE *file = fopen(inputfile, "rb");
    if (!file || (strstr(inputfile,".bmp") == NULL)){
        printf("Could not open file.\n");
        return 0;
    }
    int result;
    BITMAPFILEHEADER *bmfh = calloc(1, sizeof(BITMAPFILEHEADER));
    BITMAPINFO *bmi = calloc(1, sizeof(BITMAPINFO));
    fread(bmfh, 1, sizeof(BITMAPFILEHEADER), file);
    fread(bmi, 1, sizeof(BITMAPINFO), file);
    if (bmi->size == 40){
        BITMAPINFOV3* bmiV3 = swap(bmi, file);
        if(bmiV3->bitCount != 24){
            printf("File format cannot be processed.");
            return 0;
        }
        RGB **image = ReadImage(bmiV3, file);
        switch (cmd.n){
            case 1:
                if (cmd.fill == 0)
                    MakeSquareWithoutFill(bmiV3, image, cmd.x1, cmd.y1, cmd.l, cmd.w, cmd.red, cmd.green, cmd.blue);
                else
                    MakeSquareWithFill(bmiV3, image, cmd.x1, cmd.y1, cmd.l, cmd.w, cmd.red, cmd.green, cmd.blue, cmd.red_fill, cmd.green_fill, cmd.blue_fill);
                break;
            case 2:
                component(bmiV3, image, comp, cmd.component_value);
                break;
            case 3:
                result = TurnImage(bmfh, bmiV3, image, cmd.x1, cmd.y1, cmd.x2, cmd.y2, cmd.alpha, outputfile);
                if (result == 1){
                    return 0;
                }
                break;
            case 4:
                if(cmd.option == 1){
                    if (cmd.fill == 0)
                        CircleFromSquareWithoutFill(bmiV3, image, cmd.x1, cmd.y1, cmd.x2, cmd.y2, cmd.red, cmd.green, cmd.blue, cmd.w);
                    else
                        CircleFromSquareWithFill(bmiV3, image, cmd.x1, cmd.y1, cmd.x2, cmd.y2, cmd.red, cmd.green, cmd.blue, cmd.w, cmd.red_fill, cmd.green_fill, cmd.blue_fill);
                }
                else{
                    if (cmd.option == 2){
                        if (cmd.fill == 0)
                            CircleFromCenterWithoutFill(bmiV3, image, cmd.x_c, cmd.y_c, cmd.radius, cmd.red, cmd.green, cmd.blue, cmd.w);
                        else
                            CircleFromCenterWithFill(bmiV3, image, cmd.x_c, cmd.y_c, cmd.radius, cmd.red, cmd.green, cmd.blue, cmd.w, cmd.red_fill, cmd.green_fill, cmd.blue_fill);
                    }
                    else{
                        printf("ERROR! You did not select an option! The start file will be written!\n");
                    }
                }
                break;
            case 6:
                printFileHeader(*bmfh);
                printInfoHeader(*bmiV3);
                break;
            default:
                printf("ERROR! You have not called any functions!\n");
                return 0;
        }
        WriteImage(bmfh, bmiV3, image, outputfile);
        FreeMemory(image, bmiV3);
    }
    else{
        printf("File format cannot be processed.\n");
    }
    free(bmi);
    free(bmfh);
    fclose(file);
    return 0;
}
