#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void postorderTraversal(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main()
{
    struct Node *root = NULL;
    int numNodes;
    printf("Enter the number of nodes in the binary search tree: ");
    scanf("%d", &numNodes);

    printf("Enter node data: ");
    for (int i = 0; i < numNodes; i++)
    {
        int data;
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    printf("Postorder traversal of the binary search tree: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
