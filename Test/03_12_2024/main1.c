#include <stdio.h>
#include <stdlib.h>

void search(int valueNumber, int valueSearchNumber);
void matrix(int valueX, int valueY, int MAX, int MIN);
int getCount();

int main() {
    int X, Y;

    printf("Enter the matrix size. X: ");
    scanf("%d", &Y);
    printf("Enter the matrix size. Y: ");
    scanf("%d", &X);

    int min, max;
    printf("Enter max generated number: ");
    scanf("%d", &max);
    printf("Enter min generated number: ");
    scanf("%d", &min);

    matrix(X, Y, max, min);
    return 0;
}

void matrix(int valueX, int valueY, int MAX, int MIN){
    int allNumbers = 0;

    int array[valueX][valueY];
    int searchNumber;

    printf("Enter the desired number: ");
    scanf("%d", &searchNumber);

    for (int i = 0; i < valueX; i++) {
        for (int j = 0; j < valueY; j++) {
            array[i][j] = (rand() % (MAX - MIN + 1)) + MIN;
            array[i][j] = (rand() % (MAX - MIN + 1)) + MIN;

            if (array[i][j] == searchNumber) {
                search(array[i][j], searchNumber);
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

}

void search(int valueNumber, int valueSearchNumber){
    if (valueNumber == valueSearchNumber){
        printf("\033[32m[ %d ]\033[0m", valueNumber);
    }
}
