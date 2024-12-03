#include <stdio.h>
#include <stdlib.h>

void func1(int valueNumber, int valueSearchNumber);

int main() {
    int N = 20;
    int M = 20;

    int min = 0;
    int max = 10;

    int array[N][M];
    int searchNumber = 9;

    int allNumbers = 0;

    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < M-1; j++) {
            array[i][j] = (rand() % (max - min + 1)) + min;
            array[i][j] = (rand() % (max - min + 1)) + min;

            if (array[i][j] == searchNumber) {
                func1(array[i][j], searchNumber);
                allNumbers += 1;
            } else {
                if (array[i][j] / 10 == 0){
                    printf("  %d  ", array[i][j]);
                }
                else {
                     printf(" %d  ", array[i][j]);
                }
            }
        }
        printf("\n");
    }

    printf("All found numbers: \033[31m[ %d ]\033[0m\n", allNumbers);
    

    return 0;
}


void func1(int valueNumber, int valueSearchNumber){
    if (valueNumber == valueSearchNumber){
        printf("\033[32m[ %d ]\033[0m", valueNumber);
    }
}
