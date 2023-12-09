#include <stdio.h>
#include <math.h>
 

int main(void) {
    int n,i,x,y,z,direction ;
    
    // 1=E,2=W,3=N,4=S
    
    scanf("%d", &n);
    
    if (n>= 0 && n<= 100000){
        char  walk[n+2] ; // 0, \n
        scanf("%s", walk);
        direction=1;
        x = 0;
        y = 0;
        for (i ; i < n; i++){
            if (walk[i] == 'F') {
                if (direction == 1){
                    x++;
                } else if (direction == 2){
                    x--;
                } else if (direction == 3){
                    y++;
                } else if (direction == 4){
                    y--;
                }
                
            } else if (walk[i] == 'R'){
                 if (direction == 1){
                    direction = 4;
                } else if (direction == 2){
                    direction = 3;
                } else if (direction == 3){
                    direction = 1;
                } else if (direction == 4){
                    direction = 2;
                }
                
            } else if (walk[i] == 'L'){
                 if (direction == 1){
                    direction = 3;
                } else if (direction == 2){
                    direction = 4;
                } else if (direction == 3){
                    direction = 2;
                } else if (direction == 4){
                    direction = 1;
                }
            }
        }
        
        float z = pow((x*x+y*y),0.5);
        printf("%.4f",z);

    }
    return 0;
}