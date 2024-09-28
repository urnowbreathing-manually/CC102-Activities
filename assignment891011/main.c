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

int assignment10(){ //Program that can perform simple arithmetic operations on 2 numbers

/*
                    -- Terms --                         -- Reference --
     1st Addend   +  2nd Addend  =     Sum      || ASCII val = 43 || score = 1
       Minuend    -  Subtrahend  =  Difference  || ASCII val = 45 || score = 2
    Multiplicand  *  Multiplier  =   Product    || ASCII val = 42 || score = 0
      Dividend    /   Divisor    =   Quotient   || ASCII val = 47 || score = 3
*/

    char _operatorSymbol; //Stores user input for operator symbol
    int _operatorConvert = 0; //Stores converted char ASCII into an int score to simplify values

    //Stores pre-determined outputs depending on user inputs
    char _1stTermArray[4][14] = {"Multiplicand", "1st Addend", "Minuend", "Dividend"};
    char _2ndTermArray[4][12] = {"Multiplier", "2nd Addend", "Subtrahend", "Divisor"};

    //Stores user input values to be calculated
    double _1stTerm = 0;
    double _2ndTerm = 0;
    double _3rdTerm = 0;

    //UI text for readability
    printf("O=================(Assignment #10)=================O\n");
    printf("                 Simple  Calculator               \n");

    //Asks for user input to determine choice of operator
    printf("Select Operator {'+', '-', '*', '/'}\n   Operator: ");
    scanf(" %c", &_operatorSymbol);

    //Stores ASCII char value
    _operatorConvert = (int)_operatorSymbol;

    //Changes value stored in int _operatorConvert to a readable score
    switch(_operatorConvert){
        case 42: //Multiplication
            _operatorConvert = 0;
            break;

        case 43: //Addition
            _operatorConvert = 1;
            break;

        case 45: //Subtraction
            _operatorConvert = 2;
            break;

        case 47: //Division
            _operatorConvert = 3;
            break;

    }

    //Asks for user input for the values to be calculated
    printf("Insert the %s: ", _1stTermArray[_operatorConvert]);
    scanf("%lf", &_1stTerm);
    printf("Insert the %s: ", _2ndTermArray[_operatorConvert]);
    scanf("%lf", &_2ndTerm);

    //Selects the appropriate calculation depending on the int _operatorScore's value
    switch(_operatorConvert){
        case 0: //Multiplication
            _3rdTerm = (_1stTerm * _2ndTerm);
            break;

        case 1: //Addition
            _3rdTerm = (_1stTerm + _2ndTerm);
            break;

        case 2: //Subtraction
            _3rdTerm = (_1stTerm - _2ndTerm);
            break;

        case 3: //Division
            _3rdTerm = (_1stTerm / _2ndTerm);
            break;

    }

    //Prints result for the user to see
    printf("\nResult:\n   [%.2lf] [%c] [%.2lf] = [%.2lf]\n\n", _1stTerm, _operatorSymbol, _2ndTerm, _3rdTerm);

    //For debugging purposes...
    //printf("Debug:\n   _operatorConvert = [%d]\n\n", _operatorConvert);

    return 0;
}

int assignment11(){
    //UI text for readability
    printf("O=================(Assignment #11)=================O\n");
    printf("                   Area Calulator                \n");

    return 0;
}
