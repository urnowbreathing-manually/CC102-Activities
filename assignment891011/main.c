#include <stdio.h>
#include <stdlib.h>

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

    return 0;
}

int assignment9(){
    //UI text for readability
    printf("O=================(Assignment #9)=================O\n");
    printf("                  Grade  Evaluator                \n");

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
