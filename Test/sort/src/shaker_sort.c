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
    int i; 
    int exchange;
    char t;

    do {
        exchange = 0;

        for (i = count-1; i > 0; --i){
            if (items[i-1] > items[i]){
                t = items[i-1];
                items[i-1] = items[i];
                items[i] = t;
                exchange = 1;
            }
        }

        for (i = 1; i < count; ++i){
            if (items[i-1] > items[i]){
                t = items[i-1];
                items[i-1] = items[i];
                items[i] = t;
                exchange = 1;
            }
        }
    } while (exchange);    
}