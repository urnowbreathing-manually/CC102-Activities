#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int a = 89;

int main(){
    while(a == 89 || a == 121){
        printf("Do you want to continue? [Y/y]: ");
        do{
            a = getchar();
        } while (isspace(a));

    }

    return 0;
}

