#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node * NODE;
NODE push(NODE head){
    int data;
    NODE newNode = (NODE)malloc(sizeof(struct node));
    if(head == NULL){
        head = newNode;
        return head;
    }
    printf("Enter the data for Stack");
    scanf("%d",&data);
    newNode->data = data;
    newNode->next = head;
    // head = newNode;
    return newNode;
}
NODE pop(NODE head){
    if(head == NULL||head->next == NULL){
        return head;
    }
        NODE temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
        return head;
}
void display(NODE head){
    NODE temp = head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
void peep(NODE head,int data){
    NODE temp = head;
    while(temp != NULL){
        if(temp->data == data){
            printf("%d data found!",data);
        }
        temp = temp->next;
    }
}
int main(){
    NODE head = NULL;
    int num;
    printf("Enter the choices for operation:\n 1.Push the element to Stack\n 2.Pop an Element from stack\n 3.To get the top Element\n 4.To display the Stack\n 5.TO end the loop");
    scanf("%d",&num);
    while (1)
    {
        switch (num)
        {
        case 1:
            head = push(head);
            printf("Enter the next choice: \n");
            scanf("%d", &num);
            break;

        case 2:
            head = pop(head);
            printf("Enter the next choice: \n");
            scanf("%d", &num);
            break;

        case 3:
            peep(head,4);
            printf("Enter the next choice: \n");
            scanf("%d", &num);
            break;
        case 4:
            display(head);
            printf("Enter the next choice: \n");
            scanf("%d", &num);
            break;
        case 5:
            exit(0);
        }
    }
    return 0;

}