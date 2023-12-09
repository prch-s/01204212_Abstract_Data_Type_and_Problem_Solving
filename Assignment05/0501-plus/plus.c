#include <stdio.h>
#include <string.h>
#define SIZE 100000

int carry = 0 , Mx , My , i;
char x[SIZE],y[SIZE],sum[SIZE];

int main(void) {
    scanf("%s",x);
    scanf("%s",y);
    // len(x)>len(y)
    if (strlen(x) < strlen(y)){
        char tmp[SIZE];
        strcpy(tmp, x);
        strcpy(x, y);
        strcpy(y, tmp);
    }
    
    Mx = strlen(x)-1;
    My = strlen(y)-1;
    
    while(1){
        //printf("Mx = %d My = %d carry = %d\n",Mx,My,carry);
        //case1
        if (Mx < 0){
            //printf("case 1\n");
            break;
        } 
        //case 2
        else if (My < 0){
            //printf("case 2\n");
            int a = (x[Mx]-'0')+carry ;
            // printf("a = %d\n",a);
            if (Mx == 0){
                sum[Mx] = a;
                //printf("sum[%d] = %d\n",Mx,sum[Mx]);
            } else if (a>=10){
                sum[Mx] = a % 10;
                //printf("sum[%d] = %d\n",Mx,sum[Mx]);
                carry = 1;
            } else {
                sum[Mx] = a;
                //printf("sum[%d] = %d\n",Mx,sum[Mx]);
                carry = 0;
            } 
        }
        //case3
        else if (My >= 0){
            //printf("case 3\n");
            int a = (x[Mx]-'0') + (y[My]-'0') +carry;
           // printf("a = %d\n",a);
            if (Mx == 0){
                sum[Mx] = a;
                //printf("sum[%d] = %d\n",Mx,sum[Mx]);
            } else if (a>=10){
                sum[Mx] = a % 10;
                //printf("sum[%d] = %d\n",Mx,sum[Mx]);
                carry = 1;
            } else {
                sum[Mx] = a;
                //printf("sum[%d] = %d\n",Mx,sum[Mx]);
                carry = 0;
        }
        }
        //printf("-------------------------------------\n");
        Mx--;
        My--;

    }
    /*
    printf("********************************************************\n");
    printf("%d\n",strlen(x)-1);
    //check
    for (int i=0 ; i <= strlen(x)-1 ; i++){
        printf("%d\n",i);
        printf("sum[%d] = %d\n",i,sum[i]);
    }
     * */
    //final
    for (int i=0 ; i <= strlen(x)-1 ; i++){
        printf("%d",sum[i]);
    }
    return 0;
}