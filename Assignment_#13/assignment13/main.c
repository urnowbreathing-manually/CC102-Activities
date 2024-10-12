#include <stdio.h>
#include <stdlib.h>
#include <string.h> //For strcmp() function
//#include <ctype.h> //Remove whitespace code, not working

//Current problem: can't remove whitespace at the end of userInput string
//Current remedy: intentianlly placed whitespaces at the end of credentials[0] and credentials[1]


//char* removeWhitespace(); //Remove whitespace code, not working
//char cleanUserInput[100]; //Remove whitespace code, not working


int loginStatus = 1;                                //Check in place to detect user inputs
char userInput[100];                                //Array to store user inputs
char credentials[2][100] = {"BSCS\n", "1A\n"};      //Hardcoded default values to compare user input with

int main(){
    //Loops until the user enters the exact values stored in the credentials[] array
    while(loginStatus != 0){
        printf("Enter Username & Password:\n");
        printf("Username: ");                       //Asks for user to input username
        fgets(userInput, 100, stdin);               //Stores user input in the userInput[] array


        //removeWhitespace(userInput, cleanUserInput); //Remove whitespace code, not working

        //Compares the userInput[] with credentials[0] using the strcmp() function
        //Then assigns the absolute value of the output to the loginStatus variable
        loginStatus = abs(strcmp(userInput, credentials[0]));


        //For debugging purposes
        //printf("\nuserInput = [%s]\ncredentials[0] = [%s]\n\n", userInput, credentials[0]);
        //printf("LoginStatus = [%d]\nstrcmp = [%d]\n\n", loginStatus, strcmp(userInput, credentials[0]));



        printf("Password: ");                       //Asks for user to input username
        fgets(userInput, 100, stdin);               //Stores user input in the userInput[] array


        //removeWhitespace(userInput, cleanUserInput); //Remove whitespace code, not working

        //Compares the userInput[] with credentials[1] using the strcmp() function
        //Then assigns the absolute value of the output to the loginStatus variable
        loginStatus = loginStatus + abs(strcmp(userInput, credentials[1]));


        //For debugging purposes
        //printf("\nuserInput = [%s]\ncredentials[1] = [%s]\n\n", userInput, credentials[1]);
        //printf("LoginStatus = [%d]\nstrcmp = [%d]\n\n", loginStatus, strcmp(userInput, credentials[1]));


        //Conditional to check if loginStatus variable is equal to 0, then outputs a message based on the condition
        (loginStatus == 0) ? printf("\nLogin Successful..\n\n") : printf("\nIncorrect Credentials..\n\n");

        //Loops back to start if loginStatus == 0, otherwise the program terminates
    }

    return 0;
}
/*
char* removeWhitespace(char userInput[100], char cleanUserInput[100]){
    int index = 0;
    int arrayPointer = 0;

    while(userInput[index] == ' ' || userInput[index] == '\t' || userInput[index] == '\n'){
        index++;

    }

    for(int i = 0; userInput[i] != '\0'; i++){
        cleanUserInput[arrayPointer] = userInput[i];
        arrayPointer++;

    }

    cleanUserInput[arrayPointer] = '\0';
    printf("\ncleanUserInput = [%s]\n\n", cleanUserInput);


    return cleanUserInput;
}
*/
