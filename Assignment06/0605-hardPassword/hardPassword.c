#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int          data;
  struct node *next;
} node_t;

typedef node_t stack_t;

stack_t* push(stack_t *s , int value){
    
    node_t *new_push;
    new_push = (node_t*)malloc(sizeof(node_t));
    
    new_push -> data = value;
    new_push -> next = NULL;
    
    if (s == NULL ){
        s = new_push;
    } else {
        new_push -> next = s;
        s = new_push;
    }
    return s;
}

char  top(stack_t *s){
    return s->data;
}

stack_t* pop(stack_t *s){
    node_t *temp;
    temp = s;
    
    if ( s != NULL ) {
        s = s -> next;
        free(temp);
    }
    
    return s;
}

int empty(stack_t *s){
    if ( s == NULL ){
        return 1; //T
    } else {
        return 0; //F
    }
}

void show(stack_t *s){
    if ( s == NULL ){
        printf("NULL\n");
    } else {
        while (s != NULL) {
            printf("%c ", s->data);
            s = s->next;
        }
        printf("\n");
    }
}

int main(void) {
    stack_t *s = NULL;
    
    char password[1000000];
    
    scanf("%s",password);
    
    int len,check = 0;
    
    len = strlen(password);
    //printf("%d\n",len);
    
    for (int i = 0 ; i < 100000000000 ; i++){
        //printf("check : %d\n",check);
        //printf("%c\n",password[i]);
        if ( password[i] == 'y' ) {
            //printf("*********************\n");
            break;
        }
        if ( check == 1 ){
             if ( password[i] == top(s) ) {
                s = pop(s);
            }  
        }
        
        if ( password[i] == 'x' ) {
            check = 1;
        }
        
        if ( check == 0 ) {
            //printf("*********************\n");
            s = push(s,password[i]);
        } 
        
        //show(s);
    }
    
    //printf("*********************\n");
    
    if ( empty (s) ) {
        printf("1");
    } else {
        printf("0");
    }
    
    return 0;
}