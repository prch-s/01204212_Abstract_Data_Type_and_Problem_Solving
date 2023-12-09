#include <stdio.h>
#include <stdlib.h>

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
    if ( s != NULL ){
        return s->data;
    }
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

int empty(stack_t *s){
    if ( s == NULL ){
        return 1; //T
    } else {
        return 0; //F
    }
}
/*
void show(stack_t *s){
    if ( s == NULL ){
        printf("empty.\n");
    } else {
        while (s != NULL) {
            printf("%c ", s->data);
            s = s->next;
        }
        printf("\n");
    }
}
*/
int main(void) {
    stack_t *s = NULL;
    int n;
    scanf("%d\n",&n);
    char paren[n];

    scanf("%s",paren);
    
    for (int i = 0; i < n; i++){
        //  ) } ] and empty
        if ((paren[i] == ')' || paren[i] == '}' || paren[i] == ']') && empty(s)){
            printf("0");
            return 0;

        }
        // ( { [ push to stack_t
        if (paren[i] == '(' || paren[i] == '{' || paren[i] == '['){
            s = push(s,paren[i]);
            //show(s);
        }
        else if ( paren[i] == ')' || paren[i] == '}' || paren[i] == ']' && !empty(s) ){
            if ( paren[i] == ')' && top(s) == '(' ) {
                s = pop(s);
                //show(s);
            } else if (paren[i] == '}' && top(s) == '{') {
                s = pop(s);
                //show(s);
            } else if (paren[i] == ']' && top(s) == '[') {
                s = pop(s);
                //show(s);
            }
            else{
                printf("0");
                return 0;
            }
        }
    }
    if ( empty (s) ) {
        printf("1");
    }
    else {
        printf("0");
    }
    return 0;
}