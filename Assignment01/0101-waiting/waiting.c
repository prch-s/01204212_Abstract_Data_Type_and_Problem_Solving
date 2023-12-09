#include <stdio.h>

int main(void) {
    int x , y , total , day = 0 , hour ;
    scanf("%d %d",&x ,&y);
    if (x >= 0 && x<= 24 && y >= 0 && y <= 10000) {
            total = x+y;
            if (total <= 24) {
                hour = total;
                printf("%d %d",day,hour);
                }
            if (total > 24) {
                day = total/24;
                hour = total%24;
                printf("%d %d",day,hour);
                }
    }
    return 0;
}