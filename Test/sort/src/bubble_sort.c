#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble(char *items, int count);

int main(){
    char s[255];
    printf("Enter string: ");
    scanf("%s", s);
    bubble(s, strlen(s));
    printf("Sorted string: %s\n", s);

    return 0;
}

void bubble(char *items, int count){
    char t;

    for (int i = 1; i < count; ++i){
        for (int j = count-1; j >= i; --j){
            if (items[j-1] > items[j]){
                t = items[j-1];
                items[j-1] = items[j];
                items[j] = t;
            }
        }
    }
}