#include <stdio.h>

int main(void) {
    int x,y,answer;
    double div;
    char op;
    scanf("%d %c %d", &x , &op , &y);
     if ( x && y <= 1000 ) {
         if ( op == '+' ) {
             answer = x+y;
             printf("%d",answer);
        } else if ( op == '-' ) {
             answer = x-y;
             printf("%d",answer);
         } else if ( op == '*' ) {
             answer = x*y;
             printf("%d",answer);
         } else if ( op == '/' ) {
             div = (double) x / y;
             printf("%.2f",div);
         } else if ( op == '%' ) {
             answer = x%y;
             printf("%d",answer);
         }else {
             printf("Unknown Operator");
         }
     }
    return 0;
}

