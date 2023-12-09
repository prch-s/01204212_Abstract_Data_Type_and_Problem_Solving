#include <stdio.h>
#include <math.h>

int n,i;

int main(){
    scanf("%d",&n);
    long x = sqrt(n) + 1;
    if ( n == 0 || n == 1){
        printf("0");
        return 0;
    } else {
    for (i = 2 ; i < x  ; i ++){
        if (n%i == 0){
            printf("0");
            return 0;
        }
    }
    printf("1");
    return 0;
    }
    }
    
// O(sqrt(n))