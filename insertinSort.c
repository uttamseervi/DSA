#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node *NODE;

NODE sortedInsert(NODE head, int data)
{
    NODE temp, newnode;
    temp = head;
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = NULL;

    while (temp->link != NULL && temp->link->data < data)
    {
        temp = temp->link;
    }

    newnode->link = temp->link;
    temp->link = newnode;
    return head;
}

void printList(NODE head)
{
    NODE temp = head;
    while (temp != NULL)
    {
        printf("Data = %d\n", temp->data);
        temp = temp->link;
    }
}

NODE createList(NODE head, int n)
{
    int data;
    NODE newnode, temp;
    temp = head;

    if (head == NULL)
    {
        printf("Memory not allocated");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            newnode = (NODE)malloc(sizeof(struct node));
            printf("Enter the data for node %d: ", i);
            scanf("%d", &data);
            newnode->data = data;
            temp->link = newnode;
            newnode->link = NULL;
            temp = newnode;
        }
        return head;
    }
}

int main()
{
    NODE head;
    head = (NODE)malloc(sizeof(struct node));
    head->link = NULL;

    head = createList(head, 4);
    sortedInsert(head, -12);
    sortedInsert(head, 1);
    sortedInsert(head, 3);
    sortedInsert(head, 5);
    sortedInsert(head, 7);
    sortedInsert(head, 9);
    printList(head);

    return 0;
}
