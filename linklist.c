#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

int main(){
    printf("This is my first linked list program\n");
    struct node *n1;
    struct node *n2;
    n1 = (struct node*)malloc(sizeof(struct node));
    n2 = (struct node*)malloc(sizeof(struct node));
    n1->data=12;
    n1->next=NULL;
    n2->data=24;
    n2->next=n1;
    printf("%d\n",n1->data);
    printf("%d\n",n2->data);
    return 0;
}