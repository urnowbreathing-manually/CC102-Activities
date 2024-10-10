#include <stdio.h>
#include <stdlib.h>

#define CLOSE 4 //Ends the program through int assignmentNum
#define PI 3.1416 //Pi constant
int assignmentNum = 0; //Helps navigate through program

//All the minor functions
int assignmentSelection(); //Assignment selection panel
int assignment1(); //Assignment #1
int assignment2(); //Assignment #2
int assignment3(); //Assignment #3

int main(){ //Main Function; calls other functions in the program
    //Keeps the program looping
    while(assignmentNum != CLOSE){
    assignmentSelection();

    //If statements to select through assignments
    if(assignmentNum == 1){
        assignment1();

    } else if(assignmentNum == 2){
        assignment2();

        } else if(assignmentNum == 3){
            assignment3();

            }

    }

    return 0;
}

int assignmentSelection(){//Function to help with navigation through the program
    //UI text for readability
    printf("O===================(Selection)===================O\n");
    printf("Selection:\n   (1 = Ass.#1)\n   (2 = Ass.#2)\n   (3 = Ass.#3)\n   (4 =  Close)\n");
    printf("\nSelect assignment number: ");


    //Assigns value to assignmentNum for program naviagation
    scanf("%d", &assignmentNum);
    printf("Selected assignment: [#%d]\n\n", assignmentNum);

    return 0;
}

int assignment1(){ //Write a C program that will compute the perimeter and area of a circle with a given radius by the user.
    float radius = 0.0; //Radius of circle

    //UI text for readability
    printf("O=================(Assignment #1)=================O\n");
    printf("                 Circle Calculator               \n");
    printf("Formulas:\n   (Curcumference =   2 * pi * radius)\n   (Area          = pi * (radius) ^ 2)\n");
    printf("\nInsert circle radius: ");

    //Asks for user to input radius
    scanf("%f", &radius);
    printf("Selected Radius: [%.2f]\n", radius);

    //Calculates Circumference and Area of circle based on user input
    printf("\nRadius        = [%.2f]\nCircumference = [%.2f]\nArea          = [%.2f]\n\n", radius, 2.0 * PI * radius, PI * (radius * radius));

    return 0;
}

int assignment2(){ //Write a C program to convert specified days into years, months, weeks, and days.

    //User input goes into this variable
    int days = 0;

    //variables for storing data to be processed by the while loops below
    int dayDisplay = 0;
    int weekDisplay = 0;
    int monthDisplay = 0;
    int yearDisplay = 0;

    //UI text for readability
    printf("O=================(Assignment #2)=================O\n");
    printf("           Day-Week-Month-Year Calculator        \n");
    printf("Formulas:\n   (1 week  =   7 days)\n   (1 month =  30 days)\n   (1 year  = 365 days)\n");
    printf("\nInsert amount of days: ");

    //Asks for user to input days
    scanf("%d", &days);
    printf("Amount of Days Selected: [%d]\n", days);

    //Stores input in another int a for reference
    int a = days;
    while(a >= 365){ //First loop checks if the user input is larger than a year, which is then saved on the int yearDisplay
        yearDisplay ++;
        a = a - 365;
    }

    while(a >= 30){ //Second loop checks if the user input is larger than a month, which is then saved on the int monthDisplay
        monthDisplay ++;
        a = a - 30;
    }

    while(a >= 7){ //Third loop checks if the user input is larger than a week, which is then saved on the int weekDisplay
        weekDisplay ++;
        a = a - 7;
    }

    dayDisplay = a; //The remaining values stored in int a is saved on the int dayDisplay

    //Output is then printed for the user to see
    printf("\n[%d] day/s is equivalent to:\n   [%d] year/s, [%d] month/s, [%d] week/s, and [%d] day/s.\n", days, yearDisplay, monthDisplay, weekDisplay, dayDisplay);

    return 0;
}

int assignment3(){ //Write a C program to compute the GWA of 9 subjects

    int courseAmount = 0;
    float courseGrades = 0.0;
    float courseUnits = 0.0;
    float courseUnitsSum = 0.0;
    float gradesTimesUnits = 0.0;
    float gradesTimesUnitsSum = 0.0;

    //UI text for readability
    printf("O=================(Assignment #3)=================O\n");
    printf("                 G.W.A. Calculator               \n");
    printf("Formula:\n   ((Crs1Grds*Crs1Unit)+(Crs2Grds*Crs2Unit)+...)\n");
    printf("   ---------------------------------------------\n");
    printf("              (Sum of all Course Units)         \n");
    printf("\nInsert Course Amount: ");

    //Asks for user to input Course Amount
    scanf("%d", &courseAmount);
    printf("Selected Course Amount: [%d]\n\n", courseAmount);
    for(int a = 0; a < courseAmount; a++){

        //Asks for user to input grades and units for the specified amount of courses
        printf("Insert Grades & Units of Course [%d out of %d]:\n", courseAmount - ((courseAmount - 1) - a), courseAmount);
        printf("   Grades: ");
        scanf("%f", &courseGrades);
        printf("   Units:  ");
        scanf("%f", &courseUnits);

        //Multiplies the grades and units of 1 course and stores it in float gradesTimesUnits
        gradesTimesUnits = courseGrades * courseUnits;

        //Adds the value of float gradesTimesUnits to float gradesTimesUnitsSum every loop
        gradesTimesUnitsSum = gradesTimesUnitsSum + gradesTimesUnits;

        //Adds the value of flaot courseUnits to float courseUnitsSum every loop
        courseUnitsSum = courseUnitsSum + courseUnits;

        //Resets the 3 floats every loop
        gradesTimesUnits = 0;
        courseGrades = 0;
        courseUnits = 0;

        //For Debugging purposes; Shows values of the 2 given floats
        printf("   courseUnitSum       = [%.3f]\n   gradesTimesUnitsSum = [%.3f]\n\n", courseUnitsSum, gradesTimesUnitsSum);
    }

    //Prints the GWA for the user to see
    printf("\nGeneral Weighted Average of [%d] Courses: [%.3f]\n\n", courseAmount, gradesTimesUnitsSum / courseUnitsSum);

    return 0;
}
