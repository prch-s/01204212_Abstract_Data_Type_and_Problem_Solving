#include <stdio.h>

int main(void) {
    int Lnew = 0 , Lold = 0 , c = 0 , n = 0 , day = 0 , a = 0 , b = 0;
    scanf("%d %d %d %d", &Lnew , &Lold , &c , &n);
    if ( (Lnew && Lold && c && n  >= 0) && (Lnew && Lold && c && n  <= 10000)) {
        a = 1000*c;
        b = n*(Lold-Lnew);
        if ( a%b == 0) {
            day = a/b;
        }
        else {
            day = a/b+1;
        }
        printf("%d",day);
    }
    return 0;
}