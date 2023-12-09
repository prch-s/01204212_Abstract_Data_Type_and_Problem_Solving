#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  float data;
  struct node *next;
} node_t;

typedef node_t stack_t;

stack_t* push(stack_t *s , float value){
    
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

float  top(stack_t *s){
        return s->data;
}

stack_t* pop(stack_t *s){
    node_t *temp;
    temp = s;
    if ( s != NULL ){
        s = s -> next;
        free(temp);
    }
    return s;
}

int main(void){
    node_t *s = NULL;
    int n; 
    char postfix[n];
    scanf("%d",&n);
    scanf("%s",postfix);
    
    for( int i = 0 ; i<n ; i++){
        //push number
        float number =  postfix[i]-'0';
        if (number >= 0 && number <= 9) {
            s = push(s,number);
        //op    
        } else {
            float a,b,result;
            b = top(s);
            s = pop(s);
            a = top(s);
            s = pop(s);
            if ( postfix[i] == '+' ) {
                result = a+b;
            } else if ( postfix[i] == '-' ) {
                result = a-b;
            } else if ( postfix[i] == '*' ) {
                result = a*b;
            } else if ( postfix[i] == '/' ) {
                result = a/b;
            }
            s = push(s,result);
        }
    }
    printf("%.2f",top(s));
    return 0;
}