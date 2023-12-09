#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int          data;
  struct node *next;
} node_t;

typedef node_t queue_t;

// Write your code here
// ...
//case 1 enqueue finish
queue_t* enqueue(queue_t *q , int value){
    node_t *new_queue,*temp;
    new_queue = (node_t*)malloc(sizeof(node_t));
    
    new_queue -> data = value;
    new_queue -> next = NULL;
    
    temp = q;
    
    if (q == NULL ){
        q = new_queue;
    } else {
        while ( temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = new_queue;
    }
    return q;
}

//case 2 dequeue finish
queue_t* dequeue(queue_t *q ){
    if ( q == NULL ){
        printf("Queue is empty.\n");
        return q;
    }
   node_t *temp;
   temp = q;
   printf("%d\n", q->data );
   q = q -> next;
   free(temp);
   return q;
}

//case 3 show finish
void show(queue_t *q){
    if ( q == NULL ){
        printf("Queue is empty.\n");
    } else {
        while (q != NULL) {
            printf("%d ", q->data);
            q = q->next;
        }
        printf("\n");
    }
}

//case 4 empty finish
void empty(queue_t *q){
    if ( q == NULL ){
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }
}

//case 5 size finish
void size(queue_t *q){
    int count = 0;
    while ( q != NULL ){
        count++;
        q = q->next;
    }
    printf("%d\n",count);
}

int main(void) {
  queue_t *q = NULL;
  int      n, i, command, value;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d", &value);
        q = enqueue(q, value);
        break;
      case 2:
        q = dequeue(q);
        break;
      case 3:
        show(q);
        break;
      case 4:
        empty(q);
        break;
      case 5:
        size(q);
        break;
    }
  }
  return 0;
}