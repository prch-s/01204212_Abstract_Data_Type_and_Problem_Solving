#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int          data;
  struct node *next;
} node_t;

typedef node_t stack_t;

// Write your code here
// ...

//case 1 push finish
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

//case 2 pop finish
void  top(stack_t *s){
    if ( s == NULL ){
        printf("Stack is empty.\n");
    } else {
        printf("%d\n", s -> data );
    }
}

//case 3 pop finish
stack_t* pop(stack_t *s){
    node_t *temp;
    temp = s;
    
    if ( s != NULL ){
        s = s -> next;
        free(temp);
    }
    
    return s;
}


//case 4 empty finish
void empty(stack_t *s){
    if ( s == NULL ){
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }
}

//case 5 size finish
void size(stack_t *s){
    int count = 0;
    while ( s != NULL ){
        count++;
        s = s->next;
    }
    printf("%d\n",count);
}

int main(void) {
  stack_t *s = NULL;
  int      n, i, command, value;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d", &value);
        s = push(s, value);
        break;
      case 2:
        top(s);
        break;
      case 3:
        s = pop(s);
        break;
      case 4:
        empty(s);
        break;
      case 5:
        size(s);
        break;
      }
  }
  return 0;
}