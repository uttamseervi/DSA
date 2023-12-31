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
NODE insertBeforeNode(NODE head , int val){
    NODE newNode=(NODE)malloc(sizeof(struct node));
    NODE prev=NULL;
    NODE curr=head;
    
    printf("Enter the data for newNode: ");
    scanf("%d",&newNode->data);
    while(curr != NULL){
        if(curr->data==val){
            newNode->next=curr;
            prev->next = newNode;
            break;
        }
        prev = curr;
        curr = curr->next; 
    }
        return head;

}

int main()
{
    NODE head = (NODE)malloc(sizeof(struct node));
    // head->next = NULL;
    head = createList(head, 5);
    head = insertBeforeNode(head, 3);
    display(head);
    return 0;
}