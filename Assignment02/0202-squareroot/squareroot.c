#include <stdio.h>

int main(void) {
    
        double N, G0, answer, different ;
    
        scanf("%lf %lf", &N, &G0);
        
        if (N>= 0 && N<=100000 && G0>= 0 && G0<=100000){
            while (1) {
            answer = 0.5*(G0+N/G0);
            different = G0 - answer;
            if (different < 0){
                different = different*-1;
            } 
            printf("%.10lf %.10lf %.10lf\n", answer, G0, different);
            G0 = answer;
            if (different <= 1e-10){
                break;
            }
            }
            printf("%.10lf", answer);
        }
    return 0;
}