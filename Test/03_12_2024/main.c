#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int array[5];
    printf("Array1: ");
    for (int i = 0; i <= 4; i++){
        array[i] = i+1;
        printf("%d", array[i]);
    }
    printf("\n");

    int new;
    scanf(new);

    float magic = 15.1f;
    printf("magic = %f, array 0 = %d; array 1 = %d;\n", magic, array[0], array[1] );

    return 0;
}