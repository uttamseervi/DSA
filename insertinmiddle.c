#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *insertinmidd(struct node *head, int data, int index);
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
    traversal(head);
    printf("after insertion at the end !!!\n");
    head = insertinmidd(head, 56, 1);
    traversal(head);
    return 0;
}
struct node *insertinmidd(struct node *head, int data, int index)
{
    struct node *ptr;
    struct node *p;
    p = head;
    ptr = (struct node *)malloc(sizeof(struct node));
  
    int i=0;
    while (i != index-1)
    {
       p = p->next;
       i++;
    }
    ptr->next= p->next;
    p->next = ptr;
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
