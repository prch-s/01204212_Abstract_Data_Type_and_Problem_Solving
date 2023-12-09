#include <stdio.h>
int main()
{
    long int nummonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *charmonth[] ={" ","January","February","March","April","May","June"
                                ,"July","August","September","October","November","December"};
    long int day, month, year, i,dayoftheweek,j;

    printf("Enter year: ");
    scanf("%ld", &year);
    printf("Enter month: ");
    scanf("%ld", &month);
    
    if (year >= 1990 && year<= 5000){
        day = 0;
        //year
        for (i = 1990; i < year; i++){
            day = day + 365;
            if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
                day = day + 1;
            }
        } 
        //month
        if ((year % 4 == 0 && year % 100 != 0 ) || (year % 400 == 0)){
            nummonth[2] += 1;
        }
        for ( i = 1; i < month ; i++){
            day = day + nummonth[i];
        }
        // 1990 Feb Thu
        // day=31 31%7= 3
        // 1=Mon 2=Tue 3=Wed 4=Thu 5=Fri 6=Sat 7=Sun
        dayoftheweek = 1 + day % 7; //4
        
        printf("====================\n");
        printf("%s %ld\n", charmonth[month], year);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");
        
        j = 0;
        while (1) {
            
            if (j >= dayoftheweek){ // 0>4 , 4>4 , 31>4
                printf("%3ld ", (j - dayoftheweek) + 1);  //28
            } else {
                printf("    "); // 4 space
            }
            
            if ((j + 1) % 7 == 0){ //new week
                printf("\n");
            }
            
            j = j + 1; //32
            
            if (j == (nummonth[month] + dayoftheweek)) { // 28+4 = 32     space = 4 , Feb = 28
                break;
            }
        }
    
    }
    return 0;
}
  