
#include <stdio.h>
#include <stdlib.h>
#include "bboardfunctions.h"


int main(){

    int rows, columns, choice;
    char count = '1';
    int flag = 0;
    while(1){
        printf("How big do you want the breadboard to be? \nIt cannot be bigger than 40 * 40\n");
        printf("Enter like the size 'x y' : ");
        scanf("%d %d", &rows, &columns);
        if(rows > 0 && rows <= 40){
            if(columns > 0 && columns <= 40){
                printf("It's settled, %d x %d will be the size!\n", rows, columns);
                printf("X is Latitude || Y is Longitude\n");
                break;
            }else{
                printf("Has to be numbers between 0,40\n");
                fflush(stdin);
                continue;
            }
        }else{
            printf("Has to be numbers between 0,40\n");
            fflush(stdin);
            continue;
        }
    }   

    char** bboard = malloc(sizeof(char*) * rows);

    for (int i = 0; i < rows; i++) {
        bboard[i] = malloc(sizeof(char) * columns);
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            bboard[i][j] = '0';
        }
    }

    printBreadboard(bboard, rows, columns);
    
    while(flag == 0) {
        printf("1. Add resistor.\n");
        printf("2. print breadboard.\n");
        printf("3. Remove resistor.\n");
        printf("4. Exit..\n");
        printf("Enter a num of the above options: \n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addResistor(bboard, count, rows, columns);
                count++;
            break;
            case 2:
                printBreadboard(bboard, rows, columns);
            break;
            case 3:
                removeResistor(bboard, rows, columns, count);
            break;
            case 4:
                system("cls");
                printf("Goodbye! \n\n");
                exit(0);
            break;
            default:
                system("cls");
                printf("Enter a num between 1-4: \n");
                break;
        }
    }
    free(bboard);
    return 0;
}
