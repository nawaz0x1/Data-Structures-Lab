#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void deleteNode(struct Node **head, int key)
{
    struct Node *temp = *head;
    struct Node *prev = NULL;
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Key not found in the linked list.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}
void printLinkedList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    struct Node *head = NULL;
    int numElements;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &numElements);
    printf("Enter the element(s) to insert: ");
    for (int i = 0; i < numElements; i++)
    {
        int data;
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }
    printf("Linked list before deletion: ");
    printLinkedList(head);
    int key;
    printf("Enter the key to delete: ");
    scanf("%d", &key);
    deleteNode(&head, key);
    printf("Linked list after deletion: ");
    printLinkedList(head);
    // Free the memory occupied by the linked list
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
