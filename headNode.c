// insertion in head node in a header link list.....
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *NODE;
NODE createList(NODE header, int n)
{
    NODE temp = header;
    NODE newNode = NULL;
    if (header == NULL)
    {
        return NULL;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            newNode = (NODE)malloc(sizeof(struct node));
            if (newNode == NULL)
            {
                printf("NO memory allocated");
                return NULL;
            }
            printf("enter the data for NODE %d: ", i);
            scanf("%d", &newNode->data);
            temp->next = newNode;
            newNode->next = NULL;
            temp = newNode;
        }
        return header;
    }
}
void display(NODE header)
{
    NODE temp = header;
    while (temp != NULL)
    {
        printf("Element-> %d\n", temp->data);
        temp = temp->next;
    }
}
NODE insertionAfterHeader(NODE header)
{
    NODE newNode = (NODE)malloc(sizeof(struct node));
    printf("Enter the data for NewNOde: ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    if (header == NULL)
    {
        return newNode;
    }
    newNode->next = header->next;
    header->next = newNode;
    return header;
}

int main()
{
    NODE head = (NODE)malloc(sizeof(struct node));
    NODE header = (NODE)malloc(sizeof(struct node));
    head->data = 0;
    header->data = 1;
    head->next = header;
    header->next = NULL;
    header = createList(header,5);
    header = insertionAfterHeader(header);
    display(header);
    return 0;
}