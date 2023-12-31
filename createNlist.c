#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *firstnode;
void createNodeList(int n);
void display_list();
int main()
{
    int n;
    printf("enter the number of nodes: ");
    scanf("%d", &n);
    createNodeList(n);
    display_list();

    return 0;
}

void createNodeList(int n)
{
    struct node *newnode, *temp;
    firstnode = (struct node *)malloc(sizeof(struct node));
    if (firstnode == NULL)
    {
        printf("Memory not allocated!!!!");
    }
    else
    {
        firstnode->data = 10;
        firstnode->next = NULL;
        firstnode = temp;
        for(int i=2;i<=n;i++){
            newnode=(struct node *)malloc(sizeof(struct node));
            newnode->data=12;
            temp->next = newnode;

        }
    }
}
void display_list()
{
    struct node *temp;
    temp = firstnode;
    while (temp != NULL)
    {
        printf("Element: %d\n", temp->data);
        temp = temp->next;
    }
}
