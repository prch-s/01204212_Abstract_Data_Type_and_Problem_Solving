#include <stdio.h>
#include <stdlib.h>

void findStats(double *avg, int *maxi,int *mini, int *nums, int n){ //return alias 
	*avg = 0;
    //*nums = nums[0]
	*maxi = *nums;
	*mini = *nums;
	int i;
    
	for (i=0;i<n;i++){
		*avg += (float)(*(nums+i));
		if( *(nums+i) > *maxi ){
			*maxi = *(nums+i);
		}
		if( *(nums+i) < *mini ){
			*mini = *(nums+i);
		}
	}
	*avg /= n;
}

int main(){
    
    int n, i, maxi, mini;
    double avg;
    int* nums; //pointer to int
    
    scanf("%d", &n);
    
    nums = (int*) malloc(sizeof(int)*n); //  request memory 4*n
    
    for(i=0 ; i<n ;i++) {
        scanf("%d", nums+i); // nums+0 = nums[0]
        findStats(&avg,&maxi,&mini,nums,n); // address
    }
    
    printf("%.2f %d %d", avg, maxi, mini);
    
    return 0;
}