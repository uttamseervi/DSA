#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *insert(struct node *head,int data);
void traversal(struct node *ptr);

int main(){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));
    head->data=7;
    head->next=second;
    second->data=11;
    second->next=third;
    third->data=41;
    third->next=fourth;
    fourth->data=66;
    fourth->next=NULL;
    traversal(head);
    printf("after insertion!!!\n");
    head = insert(head,56);
    traversal(head);
    
    return 0;
}
struct node *insert(struct node *head,int data){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    return ptr;

}
void traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}
