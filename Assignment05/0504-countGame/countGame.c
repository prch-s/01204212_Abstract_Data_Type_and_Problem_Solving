#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int order;
    int number;
    struct node *next;
}node_t;

void show(node_t *startNode){
    node_t *ptr = startNode;
    //order
    printf("order  : ");
    while(ptr -> next != startNode){
        printf("%d ", ptr-> order);
        ptr = ptr->next;
    }
    printf("%d ", ptr -> order);
    printf("\n");
    //number
    printf("number : ");
    ptr = ptr -> next;
    while(ptr->next != startNode){
        printf("%d ",ptr -> number);
        ptr = ptr->next;
    }
    printf("%d ", ptr -> number);
    printf("\n");
}

int check_digit(int count , int k){
    while (count != 0){
        if (count%10 == k){ 
            return 1; //true
        }
        count = count/10;
    }
    return 0; //falst
}

int main(){
    node_t *startNode ,*temp ,*pre ;
    startNode = NULL;
    
    int    n,k;
    scanf("%d %d\n",&n,&k);
    
    for( int i=1 ; i <= n ; i++){
        int limit;
            scanf("%d",&limit);
            node_t *node;
            node = (node_t*)malloc(sizeof(node_t));
            
            node -> order = i;
            node -> number = limit;
            node -> next = NULL;
            
            //first node
            if (i == 1){
                startNode = node;
                temp = startNode;
            } else {
                temp -> next = node;
                temp = temp -> next;
            }
    }
    // circle
    temp -> next = startNode;
    temp = startNode;
    //print
    //show(startNode);
    
    //play
    
    //printf("Start!\n");
    int count = 1;
    
    while(1) {
        if ( count%k == 0 || check_digit(count,k)){
            //printf("Case 1\n");
            temp -> number -= 1;
        }
        if (temp -> number == -1){
            //printf("Case 2\n");
            pre -> next = temp -> next;
        } else {
            pre = temp;
        } 
        temp = temp -> next;
        count++;
        if ( temp -> next == temp){
            //printf("Case 3\n");
            break;
        } 
        
    }
    printf("%d\n",temp -> order);
    return 0;
}