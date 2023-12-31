#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *insertatend(struct node *head, int data);
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
    head = insertatend(head, 56);
    traversal(head);
    return 0;
}
struct node *insertatend(struct node *head, int data)
{
    struct node *ptr;
    struct node *temp;
    temp = head;
    ptr = (struct node *)malloc(sizeof(struct node));
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ptr->next = NULL;
    ptr->data = data;
    temp->next = ptr;
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
