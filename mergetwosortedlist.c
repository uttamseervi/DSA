#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node *NODE;

NODE createList(NODE head, int n)
{
    NODE temp = head;
    if (head == NULL)
    {
        printf("No memory allocated");
        return NULL;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            NODE newNode = (NODE)malloc(sizeof(struct node));
            if (newNode == NULL)
            {
                printf("No memory allocated");
                return NULL;
            }
            printf("Enter the data for node %d: ", i + 1);
            scanf("%d", &newNode->data);
            newNode->link = NULL;
            temp->link = newNode;
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
        printf("element: %d\n", temp->data);
        temp = temp->link;
    }
}

NODE sortNdMerge(NODE head1, NODE head2)
{
    NODE head3 = (NODE)malloc(sizeof(struct node));
    NODE temp = head3;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            temp->link = head1;
            head1 = head1->link;
        }
        else
        {
            temp->link = head2;
            head2 = head2->link;
        }
        temp = temp->link;
    }

    // If one list is not exhausted, append the remaining nodes
    while (head1 != NULL)
    {
        temp->link = head1;
        head1 = head1->link;
        temp = temp->link;
    }

    while (head2 != NULL)
    {
        temp->link = head2;
        head2 = head2->link;
        temp = temp->link;
    }

    return head3->link;
}

int main()
{
    NODE head1 = (NODE)malloc(sizeof(struct node));
    NODE head2 = (NODE)malloc(sizeof(struct node));
    int n;

    printf("Enter the number of nodes for the first list: ");
    scanf("%d", &n);
    head1 = createList(head1, n);

    printf("First list:\n");
    display(head1);

    printf("Enter the number of nodes for the second list: ");
    scanf("%d", &n);
    head2 = createList(head2, n);

    printf("Second list:\n");
    display(head2);

    NODE mergedList = sortNdMerge(head1->link, head2->link);

    printf("Merged and sorted list:\n");
    display(mergedList);

    return 0;
}
