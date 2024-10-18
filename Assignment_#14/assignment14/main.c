#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int shapeSelector = 16;
char shapeNouns[17][18] = {"Exit", "Line", "Striped Line", "Square", "Parallelogram", "Triangle", "Reverse Triangle",
                           "Isoceles Triangle", "Reverse Isoceles", "Hour Glass", "Diamond", "Zero",
                           "Up Arrow", "Down Arrow", "Letter X", "Bow Tie", "Invalid Input"};

int shapeSelection();
int exitProgram();
void drawLine();

int main(){
    while(shapeSelector != 0){
        shapeSelection();
        switch(shapeSelector){
            case 0:
                exitProgram();
                break;

            case 1:
                drawLine();
                break;

            case 2:

            case 3:

            case 4:

            case 5:

            case 6:

            case 7:

            case 8:

            case 9:

            case 10:

            case 11:

            case 12:

            case 13:

            case 14:

            case 15:

            default:
                printf("\n");

        }

    }

    return 0;
}

int shapeSelection(){
    //UI text for readability
    printf("[]============(ASCII Shape  Visualizer)============[]\n");
    printf("  Selection:\n");
    printf("     [0 =       %s       ][ 8 = %s]\n", shapeNouns[0], shapeNouns[8]);
    printf("     [1 =       %s       ][ 9 =    %s   ]\n", shapeNouns[1], shapeNouns[9]);
    printf("     [2 =   %s   ][10 =     %s     ]\n", shapeNouns[2], shapeNouns[10]);
    printf("     [3 =      %s      ][11 =       %s      ]\n", shapeNouns[3], shapeNouns[11]);
    printf("     [4 =   %s  ][12 =     %s    ]\n", shapeNouns[4], shapeNouns[12]);
    printf("     [5 =     %s     ][13 =    %s   ]\n", shapeNouns[5], shapeNouns[13]);
    printf("     [6 = %s ][14 =     %s    ]\n", shapeNouns[6], shapeNouns[14]);
    printf("     [7 = %s][15 =     %s     ]\n", shapeNouns[7], shapeNouns[15]);
    printf("\n  Select Shape to Visualize: ");

    //Assigns value to shapeSelector for program naviagation
    scanf("%d", &shapeSelector);
    printf("  Selected Visualization: [#%d] - [%s]\n\n", shapeSelector, shapeNouns[shapeSelector]);

    return 0;
}

int exitProgram(){
    int a = 0;

    //UI text for readability
    printf("[]=================(Exit  Program)=================[]\n");

    printf("  Do you want to exit? [y/n]: ");

    do{
        a = getchar();
    } while (isspace(a));

    if(a == 121){
        shapeSelector = 0;
        printf("\n[]=================================================[]\n");

    }   else{
            shapeSelector = 16;
            printf("\n");

        }

    return 0;
}

void drawLine(){

}
