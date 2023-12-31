#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

typedef struct node * NODE;

NODE  deleteHead(NODE head);
NODE insertATEnd(NODE head, int data);
void displaylist(NODE head);
void createlist(NODE head, int n);

int main(){
    int n;
    printf("enter the number of nodes: ");
    scanf("%d",&n);
    
    NODE head = (NODE)malloc(sizeof(struct node));
    
    printf("enter the data for the head: ");
    scanf("%d",&head->data);
    head->next = NULL;
    
  
   
    createlist(head, n);
    insertATEnd(head, 2333);
    head = deleteHead(head);
    displaylist(head);

    return 0;
}



void createlist(NODE head, int n){
    NODE temp, newnode;
    if(head == NULL){
        printf("memory not allocated");
    }
    head->next = NULL;
    temp = head;
    for(int i=1; i<=n;i++){
        newnode = (NODE)malloc(sizeof(struct node));
        printf("enter the data for the new node: ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }
       
}
void displaylist(NODE head){
    NODE temp = head;
    while(temp != NULL){
        printf("Element = %d\n",temp->data);
        temp = temp->next;
    }
}

NODE insertATEnd(NODE head, int data){
    NODE temp;
    temp = head;
    
    NODE ptr = (NODE)malloc(sizeof(struct node));
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = ptr;
    ptr->data = data;
    ptr->next = NULL;
    return head;
    
}
NODE  deleteHead(NODE head){
    if(head==NULL || head->next==NULL){
        free(head);
        return NULL;
    }
    NODE temp ;
    temp = head->next;
    head = temp;
    free(head);
    return temp;

}