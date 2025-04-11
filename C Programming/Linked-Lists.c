#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create(int data)
{
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(node **head, int val)
{
    node *newNode = create(val);
    if (newNode != NULL)
    {
        newNode->next = *head;
        *head = newNode;
    }
}

void printList(node *head)
{
    node *temp = head;
    while (temp)
    {
        printf("%i -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int find(node *head, int val)
{
    node *temp = head;
    while (temp)
    {
        if (temp->data == val)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void destroyList(node *head)
{
    if (head == NULL)
        return;
    destroyList(head->next);
    free(head);
}

void deleteNode(node *head, int val)
{
    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
}

int main(void)
{
    node *head = create(100);
    addNode(&head, 200);
    addNode(&head, 300);

    printf("HEAD -> %i\n", head->data);

    printList(head);

    int val = 200;
    if (find(head, val))
    {
        printf("%i is present in the list.\n", val);
    }
    else
    {
        printf("%i is not present in the list.\n", val);
    }

    deleteNode(head, 200);

    printList(head);

    destroyList(head);

    // printf("%i\n", head->data); // garbage value

    return 0;
}
