#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *NODE;

NODE createList(NODE head, int n)
{
    NODE newNode;
    NODE temp = head;
    if (head == NULL)
    {
        printf("Memory not allocated for head\n");
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            newNode = (NODE)malloc(sizeof(struct node));
            printf("Enter the data for Node %d : ", i);
            scanf("%d", &newNode->data);
            temp->next = newNode;
            newNode->next = NULL;
            temp = newNode;
        }
        return head;
    }
}

void display(NODE head)
{
    NODE temp = head;
    while (temp != NULL)
    {
        printf("Element = %d\n", temp->data);
        temp = temp->next;
    }
}
NODE insertAfterNode(NODE head, int val)
{
    NODE temp = head;
    NODE newNode = (NODE)malloc(sizeof(struct node));
    printf("enter the data for new node: ");
    scanf("%d",&newNode->data);
    if (head == NULL)
    {
        printf("Head is NULL no memory allocated");
        head = newNode;
    }
    
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                
                newNode->next = temp->next;
                temp->next = newNode;
                return head;
            }
            temp = temp->next;
        }
        return head;
    }


int main()
{
    NODE head = (NODE)malloc(sizeof(struct node));
    // head->next = NULL;
    head = createList(head, 5);
    head = insertAfterNode(head, 3);
    display(head);
    return 0;
}