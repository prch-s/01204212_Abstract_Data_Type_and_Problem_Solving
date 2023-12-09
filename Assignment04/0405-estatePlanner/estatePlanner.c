#include <stdio.h>
#include <math.h>

int m,n,answer;

int max(int m,int n){
    if (m >= n){
        return m;
    } else {
        return n;
    }
}
int min(int m,int n){
    if (m <= n){
        return m;
    } else {
        return n;
    }
}

int plan(int m,int n){
    int x,y,p,maxx,minn;
    
    if ( m==0 ){
        return 0;
    }
    
    if ( m==1 ){
        return m*n;
    } else {
        p = log2(m);
        x = n - pow(2, p);
        y = m - pow(2, p);
        maxx = max(x,y);
        minn = min(x,y);
        return 1+plan( min(minn,n) , max(minn,n) )+plan( min(maxx,pow(2, p)) , max(maxx,pow(2, p)) );
    }
    
}

int main(void) {
    
    scanf("%d %d",&m,&n);
    //printf("min :%d and max :%d\n",min(m,n) , max(m,n));
    answer = plan( min(m,n) , max(m,n) );
    printf("%d\n",answer);
    
    return 0;
}

// O(1)+O(1)+O(log(mn)) = O(log(mn))