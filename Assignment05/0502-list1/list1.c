#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int    data;
    struct node *next;
} node_t;

// Write your code here

//caseA finish
node_t *append(node_t *startNode) {
    int number;
    scanf(" %d",&number);
    
    node_t *ptr , *temp;
    ptr = startNode;
    temp = (node_t*)malloc(sizeof(node_t));
    
    temp -> data = number;
    temp -> next = NULL;
    
    //empty 
    if (ptr == NULL) {
        startNode = temp;
        return startNode;
    }
    //not empty
    while (ptr -> next != NULL) {
        ptr = ptr -> next;
    }
    ptr -> next = temp;
    return startNode;
}

//case G finish
void get(node_t *startNode){
    int target,count;
    scanf(" %d", &target);
    node_t *ptr;
    ptr = startNode;
    for (count = 0; count <= target ; count++){
        //printf("A = %d\n",ptr -> data);
        if (count == target){
            printf("%d\n",ptr->data);
        } else {
            ptr = ptr -> next;
        }
    }
}

//case S finish
void show(node_t *startNode){
    node_t *ptr = NULL;
    ptr = startNode;
    while (ptr != NULL){
        printf("%d ",ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
}

//case R finish
node_t *reverse(node_t *startNode){
    node_t *pre = NULL;
    node_t *post = NULL;
    node_t *ptr;
    ptr = startNode;
    
    while (ptr != NULL) {
        post = ptr -> next;
        ptr -> next = pre;
        pre = ptr;
        ptr = post;
    }
    ptr = pre;
    return ptr;
}

//case C finish
node_t *cut(node_t *startNode){
    int start,end,count;
    scanf(" %d %d", &start,&end);
    node_t *ptr;
    ptr = startNode;
    //printf("start = %d end = %d\n",start,end);
    for (count = 0 ; count <= end ; count++){
        if (count == start){
            startNode = ptr;
            if (start == end){
                ptr->next = NULL;
            }else {
                ptr = ptr->next;
            }
        }else if (count == end){
            ptr->next = NULL;
        }else {
            ptr = ptr->next;
        }
    }
    return startNode;
}

int main(void) {
    node_t *startNode;
    int    n,i;
    char   command;
    startNode = NULL;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf(" %c", &command);
        switch (command) {
            case 'A':
                startNode = append(startNode);
                break;
            case 'G':
                get(startNode);
                break;
            case 'S':
                show(startNode);
                break;
            case 'R':
                startNode = reverse(startNode);
                break;
            case 'C':
                startNode = cut(startNode);
                break;
            default:
                break;
        } 
    }
    return 0; 
}