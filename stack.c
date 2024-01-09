#include <stdio.h>
int stack[50];
int capacity = 50;
int top = -1;

void push(int data)
{
    if (capacity - 1 == top)
    {
        printf("stack is full cannot insert");
    }
    else
    {
        top++;
        stack[top] = data;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        top--;
    }
}
void peep(int data)
{
    if (top == -1)
    {
        printf("stack is empty");
    }
    for (int i = top - 1; i > -1; i--)
    {
        if (stack[i] == data)
        {
            printf("%d data found ", data);
        }
    }
}
void peek()
{
    if (top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        printf("%d", stack[top]);
    }
}
void display()
{
    if (top == -1)
    {
        printf("The list is Empty");
    }
    for (int i = top - 1; i > -1; i--)
    {
        printf("%d ->", stack[i]);
    }
}

int main()
{
    int num;
    int data;
    printf("Enter the choices for operation:\n 1.Push the element to Stack\n 2.Pop an Element from stack\n 3.To get the top Element\n 4.To display the Stack\n 5.TO end the loop");
    scanf("%d",&num);
    while (1)
    {
        switch (num)
        {
        case 1:
            printf("Enter the data to store in stack: \n");
            scanf("%d", &data);
            printf("Enter the next choice: \n");
            scanf("%d", &num);
            push(data);

            break;

        case 2:
            pop();
            printf("Enter the next choice: \n");
            scanf("%d", &num);
            break;

        case 3:
            peek();
            printf("Enter the next choice: \n");
            scanf("%d", &num);
            break;
        case 4:
            display();
            printf("Enter the next choice: \n");
            scanf("%d", &num);
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}