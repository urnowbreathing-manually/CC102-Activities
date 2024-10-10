#include <stdio.h>
#include <stdlib.h>

#define CLOSE 8 //Ends the program through int assignmentNum
int assignmentNum = 0; //Helps navigate through program

//All the minor functions
int assignmentSelection(); //Assignment selection panel
int assignment4(); //Assignment #4: Number Comparator
    void arrayPrinter(); //Prints the unsorted array for comparison
    void merge(); //Sorts and merges the values back into the original array
    void mergeSort(); //Divides the array into smaller sub arrays
int assignment5(); //Assignment #5: Coordinate Locator
    void simplifyCoords(); //Simplifies the user values for ease of comparison with hardcoded values
int assignment6(); //Assignment #6: Temperature Reader
    void tempReading(); //Displays the temperature range based on the user input
int assignment7(); //Assignment #7: Grade Descriptor


int main(){ //Main Function; calls other functions in the program
    //Keeps the program looping
    while(assignmentNum != CLOSE){
    assignmentSelection();

    //If statements to select through assignments
    if(assignmentNum == 4){
        assignment4();

    } else if(assignmentNum == 5){
        assignment5();

        } else if(assignmentNum == 6){
            assignment6();

            } else if(assignmentNum == 7){
                assignment7();

                }

    }

    return 0;
}

int assignmentSelection(){//Function to help with navigation through the program
    //UI text for readability
    printf("O===================(Selection)===================O\n");
    printf("Selection:\n   (4 = Ass.#4)\n   (5 = Ass.#5)\n   (6 = Ass.#6)\n   (7 = Ass.#7)\n   (8 =  Close)\n");
    printf("\nSelect assignment number: ");


    //Assigns value to assignmentNum for program naviagation
    scanf("%d", &assignmentNum);
    printf("Selected assignment: [#%d]\n\n", assignmentNum

    return 0;
}

int assignment4(){ //Write a C program to find the largest of three numbers

    //Stores amount of numbers to be compared
    int numberAmount = 0;

    //UI text for readability
    printf("O=================(Assignment #4)=================O\n");
    printf("                 Number Comparator               \n");
    printf("\nInsert amount of numbers to compare: ");
    scanf("%d", &numberAmount); //User input for amount of numbers to be compared
    printf("Amount of numbers to compare: [%d]\n\n", numberAmount);

    //Array to store all numbers to be compared, size of array depends on "int numberAmount"
    double numberStore[numberAmount];

    //Loop for storing user input in "double numberStore[]"
    for (int i = 0; i < numberAmount; i++) {
        printf("Insert number [%d out of %d]: ", numberAmount - ((numberAmount - 1) - i), numberAmount);
        scanf("%lf", &numberStore[i]);
        printf("Value #%u: [%.0lf] \n", i + 1, numberStore[i]);
        printf("\n");
    }

    //Function that prints the array's contents before it is sorted
    printf("Before Sorting = ");
    arrayPrinter(numberStore, numberAmount);

    //identifies the array length based on bytes for the merge-sort algorithm
    int arrayLength = sizeof(numberStore) / sizeof(numberStore[0]);


    //Merge-Sort divide and conquer algorithm
    mergeSort(numberStore, arrayLength);

    printf("\nAfter Sorting = ");
    arrayPrinter(numberStore, numberAmount);
    printf("\n");

    return 0;
}

void arrayPrinter(double numberStore[], int numberAmount){ //Function that prints the array's contents before it is sorted
    //Loops through the entire content of the array every increment of "int i"
    for(int i = 0; i < numberAmount; i++){
        if(i == 0){
            printf("{%.0lf, ", numberStore[i]);

        }   else if(i > 0 && i < numberAmount - 1){
                printf("%.0lf, ", numberStore[i]);

            }   else if(i == numberAmount - 1){
                    printf("%.0lf}", numberStore[i]);

            }

    }
}

void merge(double left[], int leftSize, double right[], int rightSize, double result[]) { // Part of the algorithm that merges the small pieces of the array back together by putting the lowest values first
    int i = 0, j = 0, k = 0;


    //Loop that compares the values with the same indexes from the 2 sub-arrays, identifies which of them has smaller and larger values, and stores them accordingly to the "double result[]" array.
    //With every loop, the 3 ints are incremented to enable navigation through each of the array's indexes
    while (i < leftSize && j < rightSize) {
        if (left[i] < right[j]) {
            result[k++] = left[i++];
        } else {
            result[k++] = right[j++];
        }
    }

    //Loop of storing the rest of the values of "double left[]" in "double result[]"
    while (i < leftSize) {
        result[k++] = left[i++];
    }

    //Loop of storing the rest of the values of "double right[]" in "double result[]"
    while (j < rightSize) {
        result[k++] = right[j++];
    }
}

void mergeSort(double numberStore[], int arrayLength) { //Part of the algorithm responsible for breaking up the array into smaller and smaller pieces until one such sub-array only consists of one element.
    int step = 1;

    //Loop that splits the array into smaller sub-arrays
    while (step < arrayLength) {
        for (int i = 0; i < arrayLength; i += 2 * step) {
            //Determines the size of the sub-arrays that will be used for sorting
            int leftSize = step;
            int rightSize = step;
            if (i + step >= arrayLength) leftSize = arrayLength - i;
            if (i + 2 * step >= arrayLength) rightSize = arrayLength - i - step;

            double left[leftSize];
            double right[rightSize];


            //Inserts the first half of the values stored in "double numberStore[]" into the left array
            for (int j = 0; j < leftSize; j++) {
                left[j] = numberStore[i + j];
            }


            //Inserts the latter half of the values stored in "double numberStore[]" into the right array
            for (int j = 0; j < rightSize; j++) {
                right[j] = numberStore[i + step + j];
            }

            //Prepares the 2 arrays to be merged
            double merged[leftSize + rightSize]; //Sets the size of the merge array by the sum of the sub-array's size
            merge(left, leftSize, right, rightSize, merged); // Part of the algorithm that merges the small pieces of the array back together by putting the lowest values first

            //Loop that stores the merged values into the original array, to be split once again until the conditions within the loop is satisfied
            for (int j = 0; j < leftSize + rightSize; j++) {
                numberStore[i + j] = merged[j];
            }
        }

        step *= 2;
    }
}

int assignment5(){ //Write a C program to accept a coordinate point in an XY coordinate system and determine in which quadrant the coordinate point lies.
    /*
    Hardcoded values for all the 9 possible combinations for coordinates
    Scores of each coordinate are determined by the following pseudocode:
        if(x is negative)
            coordsScore = (inputX + inputY) + 3
        else if (x is negative)
            coordScore = (inputX + inputY) - 3

    Below are the scores that each coordinate receives and their respective place in the 4 quadrants, including {0, 0}
       Origin = {0, 0}                  || score/s = [ 0]
    Quadrant1 = {0, 1,}, {1, 0}, {1, 1} || score/s = [ 1], [ 4], [ 5]
    Quadrant2 = {-1, 0}, {-1, 1}        || score/s = [-4], [-3]
    Quadrant3 = {-1, -1}                || score/s = [-5]
    Quadrant4 = {0, -1}, {1, -1}        || score/s = [-1], [ 3]
    */

    //Definitions for X and Y
    #define X 0
    #define Y 1

    double coords[2]; //Array for storing x and y values
    double coordsScore = 0; //Coordinate score for determining quadrant placement

    //UI text for readability
    printf("O=================(Assignment #5)=================O\n");
    printf("                Coordinate  Locator               \n");
    printf("Legend:\n   (0, 0)   = Origin\n   (+x, +y) = 1st Quadrant\n   (-x, +y) = 2nd Quadrant\n   (-x, -y) = 3rd Quadrant\n   (+x, -y) = 4th Quadrant\n");

    //User input for the coordinates
    printf("\nInsert abcissa: ");
    scanf("%lf", &coords[X]);
    printf("Insert ordinate: ");
    scanf("%lf", &coords[Y]);
    printf("Selected Coordinates: {%.0lf, %.0lf}\n\n", coords[X], coords[Y]);

    //Simplifies the user values for ease of comparison with hardcoded values
    simplifyCoords(coords);

    //After the values are simplified, the algorithm for getting the coordinate score is performed
    if(coords[X] < 0){
        coordsScore = (coords[X] + coords[Y]) - 3;

    }   else if(coords[X] > 0){
            coordsScore = (coords[X] + coords[Y]) + 3;

        }   else if(coords[X] == 0){
                coordsScore = (coords[X] + coords[Y]);

            }

    //The coordinate score then identifies the quadrant to which the user-input coordinates are located and is printed for the user to see
    printf("Location of Selected Coordinates: ");

    if(coordsScore == 0) printf("[Origin]\n\n");
    if(coordsScore == 1 || coordsScore == 4 || coordsScore == 5) printf("[1st Quadrant]\n\n");
    if(coordsScore == -4 || coordsScore == -3) printf("[2nd Quadrant]\n\n");
    if(coordsScore == -5) printf("[3rd Quadrant]\n\n");
    if(coordsScore == -1 || coordsScore == 3) printf("[4th Quadrant]\n\n");

    return 0;
}

void simplifyCoords(double coords[]){//Simplifies the user values for ease of comparison with hardcoded values
    //printf("Selected Coordinates: {%.0lf, %.0lf}\n", coords[X], coords[Y]);

    //Loop that checks if x != 0, then adds/subracts accordingly until x = 1 or -1
    while(coords[X] != 0){
        if(coords[X] > 1) coords[X] = coords[X] - 1;
        if(coords[X] < -1) coords[X] = coords[X] + 1;
        if(coords[X] == 1 || coords[X] == -1) break;
        //printf("x coord bug\n");

    }

    //Loop that checks if y != 0, then adds/subracts accordingly until y = 1 or -1
    while(coords[Y] != 0){
        if(coords[Y] > 1) coords[Y] = coords[Y] - 1;
        if(coords[Y] < -1) coords[Y] = coords[Y] + 1;
        if(coords[Y] == 1 || coords[Y] == -1) break;
        //printf("y coord bug\n");

    }

    //printf("Selected Coordinates: {%.0lf, %.0lf}\n", coords[X], coords[Y]);
}

int assignment6(){ //Write a C program to read temperature in centigrade and display a suitable message according to the temperature states provided.

    double temp = 0; // Stores user input temperature
    int tempIndex = 0; //Determines where the user input temperature lies within the predefined ranges.

    //UI text for readability
    printf("O=================(Assignment #6)=================O\n");
    printf("                Temperature  Reader               \n");
    printf("Legend:\n");
    printf(" []=============================================[]\n");
    printf(" || -20 | -10 | 0 | 10 | 20 | 30 | 40 | 50 | 60 ||\n");
    printf(" []=============================================[]\n");
    printf("           /\\  /\\   /\\   /\\   /\\   /\\ \n");
    printf("           ||  ||   ||   ||   ||   [Very Hot]\n");
    printf("           ||  ||   ||   ||   [Hot]\n");
    printf("           ||  ||   ||   [Normal Temp]\n");
    printf("           ||  ||   [Cold]\n");
    printf("           ||  [Very Cold]\n");
    printf("           [Freezing]\n\n");
    printf("O===============(Input  Selection)================O\n\n");

    //User input for temperature
    printf("Insert Temperature: ");
    scanf("%lf", &temp);
    printf("selected Temperature: [%.0lf *C]\n", temp);

    //Loop that increments "int tempIndex" by 10's until the predefined maximum is reached
    for(int i = temp; i <= 40; i +=10){
        tempIndex++;
    }

    //Displays the temperature range based on the user input
    tempReading(temp, tempIndex);

    return 0;
}

void tempReading(double temp, int tempIndex){ //Displays the temperature range based on the user input

    //Switch case is chosen depending on the tempIndex value
    switch(tempIndex){
        case 7:
            printf("[%.0lf *C] is Freezing\n", temp);
            break;

        case 6:
            printf("[%.0lf *C] is Freezing\n", temp);
            break;

        case 5:
            printf("[%.0lf *C] is Freezing\n", temp);
            break;

        case 4:
            printf("[%.0lf *C] is Very Cold\n", temp);
            break;

        case 3:
            printf("[%.0lf *C] is Cold\n", temp);
            break;

        case 2:
            printf("[%.0lf *C] is Normal Temperature\n", temp);
            break;

        case 1:
            printf("[%.0lf *C] is Hot\n", temp);
            break;

        default:
            printf("[%.0lf *C] is Very Hot\n", temp);

    }

}

int assignment7(){ //Write a C program to accept a grade and declare the equivalent description.
/*
    Below is the corresponding ASCII values for the characters used:
        A = 65, E = 69, F = 70, G = 71, V = 86
    The use is expected to input a char value, luckily, each char can be converted into an int
    The values obtained is then compared to the switch case which determines the expected output
*/
    char grade; //Stores user input grade
    int asciiGrade = 0; //Stores converted char into int ASCII value
    char gradeDesc[5][14] = {"E = Excelent", "V = Very Good", "G = Good", "A = Average", "F = Fail"}; //Array to store predetermined responses for each expected input

    //UI text for readability
    printf("O=================(Assignment #7)=================O\n");
    printf("                 Grade  Descriptor              \n");
    printf("Legend:\n   E = Excelent\n   V = Very Good\n   G = Good\n   A = Average\n   F = Fail\n");
    printf("Protip:\n   Use uppercase letters for proper operation,\n   lowercase input is yet to be implemented\n   in future updates.\n\n");

    //User input grade
    printf("Insert Grade: ");
    scanf("%s", &grade);

    //Converts char into ASCII int
    asciiGrade = grade;

    //Switch case for the 5 possible inputs
    switch(asciiGrade){
        case 65:
            asciiGrade = 3;
            break;

        case 69:
            asciiGrade = 0;
            break;

        case 70:
            asciiGrade = 4;
            break;

        case 71:
            asciiGrade = 2;
            break;

        case 86:
            asciiGrade = 1;
            break;

    }

    //Output is then printed for the user to see
    printf("\nGrade Selected: [%s]\n", gradeDesc[asciiGrade]);


    return 0;
}

