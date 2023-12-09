#include <stdio.h>

int main(void) {
    int x = 0 , y = 0 , z = 0 , total = 0;
    char hungry,sick;
    scanf("%d %d %d\n", &x , &y , &z );
    scanf("%c %c", &hungry , &sick);
    total = x;
    if ( (x && y && z  > 0) && (x && y && z  <= 1000) ) {
           if (hungry == 'Y' || hungry == 'y'){
               total = total + y;
           } 
           if (sick == 'Y' || sick == 'y'){
                if (total%z != 0){
                    total = total / z;
                    total += 1;
                }
                else {
                    total = total / z;
                }
            }
    }
    printf("%d",total);
    return 0;
}
