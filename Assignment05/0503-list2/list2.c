#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data_0;
    double data_1;
    char data_2[100];
    int type;
    struct node *next;
}node_t;

// Write your code here

//case A finish
node_t *append(node_t *startNode) {
    int check;
    scanf(" %d",&check);
    
    int number;
    double decimal;
    char alpha[20];
    //check type
    if (check == 0){
        scanf(" %d",&number);
    }else if(check == 1){
        scanf(" %lf",&decimal);
    }else if(check == 2){
        scanf(" %s",alpha);
    }
    
    node_t *ptr , *temp;
    ptr = startNode;
    temp = (node_t*)malloc(sizeof(node_t));
    
    //configure
    if (check == 0) {
        temp->data_0  = number;
        temp->type = 0;
    }else if (check == 1) {
        temp->data_1  = decimal;
        temp->type = 1;
    }else if (check == 2) {
        strcpy(temp->data_2,alpha);
        temp->type = 2;
    }
    //last
    temp -> next = NULL;
    
    //empty
    if (ptr == NULL){
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
            if (ptr -> type == 0){
                printf("%d ",ptr -> data_0);
            } else if (ptr -> type == 1){
                printf("%lf ",ptr -> data_1);
            } else if (ptr -> type == 2){
                printf("%s ",ptr -> data_2);
            }
        } else {
            ptr = ptr -> next;
        }
    }
    printf("\n");
}

//case S finish
void show(node_t *startNode){
    node_t *ptr = NULL;
    ptr = startNode;
    while (ptr != NULL){
        if (ptr -> type == 0){
            printf("%d ",ptr -> data_0);
        } else if (ptr -> type == 1){
            printf("%lf ",ptr -> data_1);
        } else if (ptr -> type == 2){
            printf("%s ",ptr -> data_2);
        }
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
node_t *show_reverse(node_t *startNode){
    node_t *rev = NULL;
    rev = reverse(startNode);
    show(rev);
    startNode = reverse(rev);
    return startNode;
}

//case I (insert after target) finish
void insert(node_t *startNode){
    int target,count=0;
    scanf(" %d", &target);
    
    //form Case A
    int check;
    scanf(" %d",&check);
    
    int number;
    double decimal;
    char alpha[20];
    //check type
    if (check == 0){
        scanf(" %d",&number);
    }else if(check == 1){
        scanf(" %lf",&decimal);
    }else if(check == 2){
        scanf(" %s",alpha);
    }
    
    node_t *ptr , *temp;
    ptr = startNode;
    temp = (node_t*)malloc(sizeof(node_t));
    
    //configure
    if (check == 0) {
        temp->data_0  = number;
        temp->type = 0;
    } else if (check == 1) {
        temp->data_1  = decimal;
        temp->type = 1;
    } else if (check == 2) {
        strcpy(temp->data_2,alpha);
        temp->type = 2;
    }
    //last
    temp -> next = NULL;
    
    for (count = 0; count <= target ; count++){
        if (target == count){
            temp -> next = ptr -> next;
            ptr -> next = temp;
            break;
        }
        ptr = ptr -> next;
    }
}

//case D (delete after target) finish
node_t *delete(node_t *startNode){
    int target;
    scanf(" %d", &target);
    
    node_t *ptr , *pre , *cur;
    ptr = startNode;
    pre = startNode;
    cur = startNode;
    
    if (target == 0){
        startNode = ptr -> next;
        free(ptr); //just delete
    } else{
        while(target != 0){
            pre = cur;
            cur = cur -> next;
            target--;
        }
        pre -> next = cur -> next;
        free(cur);
    }
    
    return startNode;
}

//case C finish
void change(node_t *startNode){
    int target,count=0;
    scanf(" %d", &target);
    
    //form Case A
    int check;
    scanf(" %d",&check);
    
    int number;
    double decimal;
    char alpha[20];
    //check type
    if (check == 0){
        scanf(" %d",&number);
    }else if(check == 1){
        scanf(" %lf",&decimal);
    }else if(check == 2){
        scanf(" %s",alpha);
    }
    
    node_t *ptr , *temp;
    ptr = startNode;
    
    for (count = 0; count <= target ; count++){
        if (target == count){
            if (check == 0) {
                ptr->data_0  = number;
                ptr->type = 0;
            } else if (check == 1) {
                ptr->data_1  = decimal;
                ptr->type = 1;
            } else if (check == 2) {
                strcpy(ptr->data_2,alpha);
                ptr->type = 2;
            }
            break;
        } else {
            ptr = ptr -> next;
        }
    }
}

//case E finish
void is_empty(node_t *startNode){
    if (startNode == NULL){
       printf("Empty\n");
       return ;
    } 
    printf("Not Empty\n");
    return ;
}

//case L finish
void length(node_t *startNode){
    node_t *ptr;
    ptr = startNode;
    int len = 0;
    while(ptr != NULL){
        ptr = ptr -> next;
        len++;
    }
    printf("%d\n",len);
    return ;
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
                startNode = show_reverse(startNode);
                break;
            case 'I':
                insert(startNode);
                break;
            case 'D':
                startNode = delete(startNode);
                break;
            case 'C':
                change(startNode);
                break;
            case 'E':
                is_empty(startNode);
                break;
            case 'L':
                length(startNode);
                break;
            default:
                break;
        } 
    }
    return 0; 
}