#include <stdio.h>

int main(void) {
    char a , b;
    int dif = 0;
    scanf("%c %c", &a , &b);  
    if (a > b) {
        dif = a - b; }
    else {
        dif = b - a; }
    printf("%d ", dif);
    return 0;
}