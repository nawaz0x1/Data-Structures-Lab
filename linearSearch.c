#include <stdio.h>

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i; // Element found at position i
        }
    }
    return -1; // Element not found
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    int position = linearSearch(arr, n, key);
    if (position != -1)
    {
        printf("Element found at position: %d\n", position);
    }
    else
    {
        printf("Element not found\n");
    }
    return 0;
}