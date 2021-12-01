
#include <stdio.h>
#include <stdlib.h>
#include "bboardfunctions.h"


void printBreadboard(char** bboard, int rows, int columns){
    printf("    ");
    for(int i = 0; i < columns; i++){
        if(i < 9){
            printf("%d  ", i+1);
        }else{
            printf("%d ", i+1);
        }
    }
    printf("\n");

    for (int i = 0; i < rows; i++){
        if(i < 9){
            printf("%d   ", i+1);
            for (int j = 0; j < columns; j++){
                printf("%c  ", bboard[i][j]);
            }
            printf("\n");
        }else{
            printf("%d  ", i+1);
            for (int j = 0; j < columns; j++){
                printf("%c  ", bboard[i][j]);
            }
            printf("\n");
        }
    }
}

double addResistor(char** bboard, char count, int rows, int columns){
    int row1, column1, column2;
    while(1){
        
        printf("Where do you want to place the first leg: X, Y\n: ");
        scanf("%d %d", &row1, &column1);
        if(row1 > rows || column1 > columns){
            printf("Cannot be bigger than the Breadboard itself.");
            continue;
        }
        printf("Where do you want to place the second leg: Y\n: ");
        scanf("%d", &column2);
        if(row1 <= 0 || column1 <= 0 || column2 <= 0 || column2 > columns){
            printf("Has to be between the range of 1 and %d.\n", rows);
            continue;
        }else if(column1 == column2){
            printf("Can't place resistor legs in the same slot.\n");
            continue;
        }else if(bboard[row1-1][column1-1] > '0' || bboard[row1-1][column2-1] == '-' || bboard[row1-1][column2-1] > '0'){
            printf("Slot already occupied.\n");
            continue;
        }else{
            bboard[row1-1][column1-1] = count;
            bboard[row1-1][column2-1] = count;
            if (column1 > column2){
                for(int i = column2 + 1; i < column1; i++){
                    bboard[row1-1][i-1] = '-';
                }
            }
            for(int i = column1 + 1; i < column2; i++){
            bboard[row1-1][i-1] = '-';
            }
            printf("Resistor #%c added\n", count);
            break;
        }
    }
    return 0;
}

int removeResistor(char** bboard, int rows, int columns, char count){
    char resNum;
    while(1){
        printf("Whats the number of the resistor you want to remove?\n:");
        scanf(" %c", &resNum);
        if(resNum < count){
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++){
                    if(bboard[i][j] == resNum){
                        bboard[i][j] = '0';
                        for(;j < columns; j++){
                            if(bboard[i][j] == resNum){
                                bboard[i][j] = '0';
                                break;
                            }else{
                                bboard[i][j] = '0';
                            }
                            
                        }
                    }     
                }
            }
            printf("Resistor removed\n");
            break;
        }else{
            printf("Resistor doesn't exist\n");
            break;
        }
      
    }
    return 0;
}


/*
int bbLoop(char** bboard, int rows, int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; i < columns; j++){

        }
    }

}
*/
