#include <stdio.h>

int m,p,n,i,j,k,ans=0;

char message[100000];
char check[100000];
char answer[100000];

int main(void){
    scanf("%d %d %d ",&m,&p,&n);
    scanf("%s",message);
    scanf("%s",check);
    
    for( i=0; i<m ; i += 1){
        
        int x=i;
        if (i <= m-p){
        
            int dif = 0;
            for( j=0 ; j< p ; j += 1){
                if (message[i+j] != check[j]){
                    dif += 1;
                }
            }
            //printf("%d\n",dif);
            if(dif <= n){
                
                answer[ans] = '[';
                ans += 1;
                for( k=0; k<p ; k += 1){
                    if(message[i+k] != check[k]){
                        answer[ans] = '?';
                        ans += 1;
                    }
                    else{
                        answer[ans] = check[k];
                        ans += 1;
                    }
                }
                answer[ans] = ']';
                ans += 1;
                x = i+p-1;
            }
            else {
                x = i;
            }
        }
        
        if ( x == i ) {
            answer[ans] = message[i];
            ans += 1;
        }
        else {
            i = x;
        }
    }
    printf("%s\n",answer);
    return 0;
}

/* test case
18 3 0
acabababababcbabab
aba
ac[aba]b[aba]babcb[aba]b
*
18 3 1
acabababababcbabab
aba
[a?a]b[aba]b[aba]b[?ba]bab
 * 
18 3 1
acabababababcabbab
abc
ac[ab?]b[ab?]b[abc][ab?]ab
 * 
15 4 2
AAAGTGTGTCTGATT
GTAT
AAA[GT?T][GT?T][G??T
*/