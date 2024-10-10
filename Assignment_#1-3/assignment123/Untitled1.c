
//#include <stdio.h>
//#include <stdlib.h>

/*
int assignment3(){ //Write a C program to compute the GWA of 9 subjects

    //Where user input is stored
    int courseAmount = 0;

    //Sum of all grades stored in the float gwa[]
    float sumOfCourseGrades = 0.0;

    //Array to store multiple user inputs
    float gwa[courseAmount];

    //UI text for readability
    printf("O=================(Assignment #3)=================O\n");
    printf("                 G.W.A. Calculator               \n");
    printf("Insert Course Amount: ");

    //Asks for user to input Course Amount
    scanf("%d", &courseAmount);
    printf("Selected Course Amount: [%d]\n\n", courseAmount);

    //Asks for user to input grades and units for the specified amount of courses
    for(int a = 0; a < courseAmount; a ++){
        printf("Insert Grades of Course [%d out of %d]: ", courseAmount - ((courseAmount - 1) - a), courseAmount);
        scanf("%f", &gwa[a]);

    }

    //Adds all the grades stored in the array
    for(int a = 0; a < courseAmount; a ++){
        sumOfCourseGrades = sumOfCourseGrades + gwa[a];

    }

    //Prints the GWA for the user to see
    printf("\nGeneral Weighted Average of [%d] Courses: [%f]\n\n", courseAmount, sumOfCourseGrades / courseAmount);

    return 0;
}


int assignment3(){ //Write a C program to compute the GWA of 9 subjects
    int courseAmount = 0; //Stores user input; Amount of courses
    int _courseAmount = 0; //Hard-coded failsafe against int overflow
    float courseGrades[courseAmount]; //Array to store every course grades
    float courseUnits[courseAmount]; //Array to store every course units
    float courseUnitsSum = 0.0; //Stores sum of all course units
    float gradesTimesUnits[courseAmount]; //Array to store every course's (Grades * Units)
    float gradesTimesUnitsSum = 0.0; //Stores sum of all course (Grades * Units)

    //UI text for readability
    printf("O=================(Assignment #3)=================O\n");
    printf("                 G.W.A. Calculator               \n");
    printf("Formula:\n   ((Crs1Grds*Crs1Unit)+(Crs2Grds*Crs2Unit)+...)\n");
    printf("   ---------------------------------------------\n");
    printf("              (Sum of all Course Units)         \n");
    printf("\nInsert Course Amount: ");

    //Asks for user to input Course Amount
    scanf("%d", &courseAmount);
    _courseAmount = courseAmount;
    printf("Selected Course Amount: [%d]\n\n", courseAmount);

    //Asks for user to input grades and units for the specified amount of courses
    for(int a = 0; a < courseAmount; a++){
        if(courseAmount > 100){
            courseAmount = _courseAmount;
        }
        printf("Reference: [%d], [%d]\n", a, courseAmount);
        printf("courseGrades[%d] = {", courseAmount);
        for(int a = 0; a < courseAmount; a++){
            printf("[%f]", courseGrades[a]);
        }
        printf("}");
        printf("\ncourseUnits[%d] = {", courseAmount);
        for(int a = 0; a < courseAmount; a++){
            printf("[%f]", courseUnits[a]);
        }
        printf("}\n");
        printf("Insert Grades & Units of Course [%d out of %d]:\n", courseAmount - ((courseAmount - 1) - a), courseAmount);
        printf("   Grades: ");
        scanf("%f", &courseGrades[a]);
        printf("   Units: ");
        scanf("%f", &courseUnits[a]);
        printf("\n");

    }

    //Performs GWA calculation
    for(int a = 0; a < courseAmount; a ++){
        //Multiplies grades and units of each course every increment of int a and stores it in float gradesTimesUnits[]
        gradesTimesUnits[a] = courseGrades[a] * courseUnits[a];

        //Takes the sum of all units of every course and stores it in float courseUnitsSum
        courseUnitsSum = courseUnitsSum + courseUnits[a];

    }

    for(int a = 0; a < courseAmount; a ++){
        //Takes the sum of all (Grades * Units) of every course and stores it in float gradesTimesUnitsSum
        gradesTimesUnitsSum = gradesTimesUnitsSum + gradesTimesUnits[a];

    }

    //Prints the GWA for the user to see
    printf("General Weighted Average of [%d] Courses: [%f]\n\n", courseAmount, gradesTimesUnitsSum / courseUnitsSum);

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

        //Set all values inside array to 0
        if(a == 0){
            for(int b = 0; b < courseAmount; b++){
                gradesTimesUnits[b] = 0.0;

            }


        }

      //For debugging purposes; Displays values inside array
        printf("gradesTimesUnits[%d] =\n   {", courseAmount);
        for(int a = 0; a < courseAmount; a++){
            printf("[%.3f]", gradesTimesUnits[a]);

        }

        printf("}\n\n");

        //Asks for user to input grades and units for the specified amount of courses
        printf("Insert Grades & Units of Course [%d out of %d]:\n", courseAmount - ((courseAmount - 1) - a), courseAmount);
        printf("   Grades: ");
        scanf("%f", &courseGrades);
        printf("   Units:  ");
        scanf("%f", &courseUnits);
        printf("\n");

        //Allows last value in array to be printed in console
        if(a == courseAmount){
            printf("gradesTimesUnits[%d] =\n   {", courseAmount);
            for(int a = 0; a < courseAmount; a++){
                printf("[%.3f]", gradesTimesUnits[a]);

            }

            printf("}\n\n");
        }

        //Multiplies the 2 user inputs and stores it in float gradesTimesUnits[]
        gradesTimesUnits = courseGrades * courseUnits;

        gradesTimesUnitsSum = gradesTimesUnitsSum + gradesTimesUnits;

        //Adds all the user input that the float courseUnits receives every loop
        courseUnitsSum = courseUnitsSum + courseUnits;

        //Resets the 3 floats every loop
        gradesTimesUnits = 0;
        courseGrades = 0;
        courseUnits = 0;
    }

    //Adds the sum of all values stored in the gradesTimesUnits[] and stores it in float gradesTimesUnitsSum
    for(int a = 0; a < courseAmount; a++){
        gradesTimesUnitsSum = gradesTimesUnitsSum + gradesTimesUnits[a];

    }

    //For Debugging purposes; Shows values of the 2 given floats
    printf("courseUnitSum       = [%.3f]\ngradesTimesUnitsSum = [%.3f]\n", courseUnitsSum, gradesTimesUnitsSum);

    //Prints the GWA for the user to see
    printf("\nGeneral Weighted Average of [%d] Courses: [%.3f]\n\n", courseAmount, gradesTimesUnitsSum / courseUnitsSum);



    return 0;
}
*/


