#include <stdio.h>

int main(void) {
    int day , month , year , day_feb = 28, total ;
    scanf("%d/%d/%d", &day , &month , &year);
    
    total = day;
    
     if( (year % 4 == 0 && year % 100 != 0 ) || (year % 400 == 0) ){
        day_feb = 29;
    }
    
    switch(month){
        case 2:
            total += 31;
            break;
        case 3:
            total += 31+day_feb;
            break;
        case 4:
            total+= 31+day_feb+31;
            break;
        case 5:
            total += 31+day_feb+31+30;
            break;
        case 6:
            total += 31+day_feb+31+30+31;
            break;
        case 7:
            total+= 31+day_feb+31+30+31+30;
            break;            
        case 8:
            total += 31+day_feb+31+30+31+30+31;
            break;
        case 9:
            total += 31+day_feb+31+30+31+30+31+31;
            break;
        case 10:
            total += 31+day_feb+31+30+31+30+31+31+30;            
            break;            
        case 11:
            total += 31+day_feb+31+30+31+30+31+31+30+31;            
            break;                        
        case 12:
            total += 31+day_feb+31+30+31+30+31+31+30+31+30;            
            break;                                    
    }
    printf("%d", total);

    return 0;
}