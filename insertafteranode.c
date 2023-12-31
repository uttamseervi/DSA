#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *insertafternode(struct node *head,struct node *prevnode,int data);
void traversal(struct node *ptr);

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));
    head->data = 7;
    head->next = second;
    second->data = 11;
    second->next = third;
    third->data = 41;
    third->next = fourth;
    fourth->data = 66;
    fourth->next = NULL;
    printf("before insertion!!\n");
    traversal(head);
    printf("after insertion at the end !!!\n");
    head = insertafternode(head,second,56);
    traversal(head);
    return 0;
}
struct node *insertafternode(struct node *head,struct node *prevnode,int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = prevnode->next;
    prevnode->next = ptr;
    ptr->data = data;
   
        return head;
}
void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
