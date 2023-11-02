// Name: Maahir Azmain Chowdhury
// UID: U46043961
/*Program: A Program to find the exclusive or of 2
input arrays and storing them in a different array*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototype
void exclusive_or(int *a, int n1, int *b, int n2, int *c, int *size);

int main()
{
    // Initializing the size of Array #1, Array #2 and the resulting Array
    int lenArr1 = 0;
    int lenArr2 = 0;
    int size = 0;

    // Taking input for the size of Array #1
    printf("Enter length of array #1: ");
    scanf("%d", &lenArr1);

    // Initializing Array #1
    int arr1[lenArr1];

    // Taking input for the elements to be stored in Array #1
    printf("Enter array elements: ");
    for (int i = 0; i < lenArr1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    // Taking input for the size of Array #2
    printf("Enter length of array #2: ");
    scanf("%d", &lenArr2);

    // Initializing Array #2
    int arr2[lenArr2];

    // Taking input for the elements to be stored in Array #2
    printf("Enter array elements: ");
    for (int j = 0; j < lenArr2; j++)
    {
        scanf("%d", &arr2[j]);
    }

    /* Initializing the resulting Array and giving it a size equivalent
       to the sum of the size of both the input arrays*/
    int arr3[lenArr1 + lenArr2];

    // Calling the function to find the uncommon elements between the 2 arrays
    exclusive_or(arr1, lenArr1, arr2, lenArr2, arr3, &size);

    // Printing out the elements from the resulting Array
    printf("Output: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr3[i]);
    }

    return 0;
}

void exclusive_or(int *a, int n1, int *b, int n2, int *c, int *size)
{
    // Initializing the pointers for Array #1 & Array #2
    int *arr1ptr = a;
    int *arr2ptr = b;
    
    // Initializing the counter variable for the size of the resulting array
    int k = 0;

    /* Comparing the elements of Array #1 with Array #2 and storing
       the uncommon elements of Array #1 in the resulting array using both the loops*/
    for (int i = 0; i < n1; i++)
    {
        /* Initializing a Boolean variable to check if there is a common element
           in both Array #1 and Array #2*/
        int found = 0;

        for (int j = 0; j < n2; j++)
        {
            if (*(arr1ptr + i) == *(arr2ptr + j))
            {
                found = 1;
                break;
            }
        }
        // If an element is not common, the element of Array #1 is stored in the resulting array
        if (!found)
        {
            *(c + k) = *(arr1ptr + i);
            k++;
        }
    
    }

    /* Comparing the elements of Array #2 with Array #1 and storing
       the uncommon elements of Array #2 in the resulting array using both the loops*/
    for (int i = 0; i < n2; i++)
    {
        /* Initializing a Boolean variable to check if there is a common element
           in both Array #1 and Array #2*/
        int found = 0;

        for (int j = 0; j < n1; j++)
        {
            if (*(arr2ptr + i) == *(arr1ptr + j))
            {
                found = 1;
                break;
            }
        }
        
        // If an element is not common, the element of Array #1 is stored in the resulting array
        if (!found)
        {
            *(c + k) = *(arr2ptr + i);
            k++;
        }
    
    }

    // Updating the size of the resulting array using the counter variable
    *size = k;
}