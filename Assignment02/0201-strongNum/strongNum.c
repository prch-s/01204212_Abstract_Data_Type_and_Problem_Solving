#include <stdio.h>


int main(void) {
    int i,n,single,check,m,j,sum,plus = 0 ;

    scanf("%d",&n) ;
    
    if (n>= 0 && n<=100000){
        for ( i=0 ; i<n ; i++) {
            scanf("%d",&m) ; //m = 10
            if (m>= 0 && m<=1000000){
                for (j = m-1 ; j>0 ; j--){ //9            
                    sum = 0;
                    check = j;
                    while ( check > 0) {  //9>0
                        single = check % 10; //9
                        int k =1;
                        plus = 1;
                        while (k <= single){
                                plus = plus * k;
                                k++;
                        }
                        sum = sum + plus; //9!
                        check = check / 10; //9/10 = 0
                    }
                    if (sum == j){
                        printf("%d\n", sum);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}

