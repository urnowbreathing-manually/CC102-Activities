#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLOSE 12 //Ends the program through int assignmentNum
int assignmentNum = 0; //Helps navigate through program

//All the minor functions
int assignmentSelection(); //Assignment selection panel
int assignment8();
int assignment9();
int assignment10();
int assignment11();

int main(){ //Main Function; calls other functions in the program
    //Keeps the program looping
    while(assignmentNum != CLOSE){
       assignmentSelection();

       //If statements to select through assignments
       if(assignmentNum == 8){
           assignment8();

       } else if(assignmentNum == 9){
           assignment9();

           } else if(assignmentNum == 10){
               assignment10();

               } else if(assignmentNum == 11){
                   assignment11();

                   }

    }


    return 0;
}

int assignmentSelection(){//Function to help with navigation through the program
    //UI text for readability
    printf("O===================(Selection)===================O\n");
    printf("Selection:\n   (8 = Ass.#8)\n   (9 = Ass.#9)\n   (10 = Ass.#10)\n   (11 = Ass.#11)\n   (12 =  Close)\n");
    printf("\nSelect assignment number: ");

    //Assigns value to assignmentNum for program naviagation
    scanf("%d", &assignmentNum);
    printf("Selected assignment: [#%d]\n\n", assignmentNum);

    return 0;
}

int assignment8(){

    //UI text for readability
    printf("O=================(Assignment #8)=================O\n");
    printf("                  Time   Settings                 \n");
    printf("Legend:\n   HH = Hours  ; 01HH =  60MM\n   MM = Minutes; 01MM =  60SS\n   SS = Seconds; 01SS = 100MS\n\n");

    printf("Enter time in HH:MM:SS format: ");

    return 0;
}

int assignment9(){ //Program that takes the student's scores on [n] amount of subjects and gives an assessment

    int subjectAmount = 0; //Store user input for subject amount
    int subjectScore = 0; //Temporarily stores user input for scores of the current subject
    int assessmentIndicator = 0; //Gives access to the 3 elements of the string array

    char studentAssessment[3][8] = {"PASS", "RE-EXAM", "FAIL"}; //Stores the expected outputs of the program

    //UI text for readability
    printf("O=================(Assignment #9)=================O\n");
    printf("                  Score  Evaluator                \n");
    printf("Info:\n   Pass    = All scores >= 40\n   Re-exam = Scored 30 - 39 in any subject\n   Fail    = Scored < 30 in any subject\n\n");

    //Asks for user input for subject amount
    printf("Insert Subect Amount: ");
    scanf("%d", &subjectAmount);
    printf("Selected Subject Amount: [%d]\n\n", subjectAmount);

    //Loops for [subjectAmount] of times to get user input on the scores of the subjects
    for(int a = 0; a < subjectAmount; a++){

        //Asks for user input on the score of the current subject
        printf("Insert Score of Subject [%d out of %d]:\n", subjectAmount - ((subjectAmount - 1) - a), subjectAmount);
        printf(" Score: ");
        scanf("%d", &subjectScore);

        //Conditions for determining student assessment
        if(assessmentIndicator == 0){
            assessmentIndicator = (subjectScore >= 40) ? 0 : 1;

        }

        if(assessmentIndicator == 1){
            assessmentIndicator = (subjectScore >= 30) ? 1 : 2;

        }

    }

    //Prints the expected assessment for the student
    printf("\n\nStudent Assessment: [%s]\n\n", studentAssessment[assessmentIndicator]);

    return 0;
}

int assignment10(){
    //UI text for readability
    printf("O=================(Assignment #10)=================O\n");
    printf("                 Simple  Calculator               \n");

    return 0;
}

int assignment11(){
    //UI text for readability
    printf("O=================(Assignment #11)=================O\n");
    printf("                   Area Calulator                \n");

    return 0;
}
