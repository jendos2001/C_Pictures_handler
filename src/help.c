#include "help.h"

void help(){
    printf("-h or --Help - call a reference\n");
    printf("--InputFile - name of input file\n");
    printf("--OutputFile - name of output file\n");
    printf("-i or --Information - an information about file\n");
    printf("-s or --Square - draw a square\n");
    printf("-f or --Filter - sets the color component to the entered value\n");
    printf("-t or --Turn_Image - rotation of the image by the entered value\n");
    printf("-c or --Circle - draw a circle\n");
    printf("--X_UpLeft - x coordinate of the upper left corner\n");
    printf("--Y_UpLeft - y coordinate of the upper left corner\n");
    printf("--X_DownRight - x coordinate of the bottom right corner\n");
    printf("--Y_DownRight - y coordinate of the bottom right corner\n");
    printf("--Length - side length of a square\n");
    printf("--Width - circle or square width\n");
    printf("-r or --Red - red line component\n");
    printf("-g or --Green - green line component\n");
    printf("-b or --Blue - blue line component\n");
    printf("--Fill - fill the figure\n");
    printf("--Red_Fill - red fill component\n");
    printf("--Green_Fill - green fill component\n");
    printf("--Blue_Fill - blue fill component\n");
    printf("--Component - component to be changed: Red, Green, Blue.\n");
    printf("--Component_Value - value to be changed\n");
    printf("--Alpha - angle to rotate the image\n");
    printf("-o or --Option - circle drawing method:\n");
    printf("1 - inscribed in a square;\n");
    printf("2 - using center and radius coordinates.\n");
    printf("--X_Center - x coordinate of circle\n");
    printf("--Y_Center - y coordinate of circle\n");
    printf("--Radius - radius of circle\n");
}