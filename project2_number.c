// Name: Maahir Azmain Chowdhury
// UID: U46043961
/*Program: A Program to determine if a number is considered special
It prints "yes" if it is special and prints "no" otherwise*/


#include <stdio.h>
#include <stdlib.h>

// Function to check if the digit 3 is present
int contains3(int d)
{
    while (d > 0)
    {
        // Isolating the last digit from the number and checking if it contains 3
        if (d % 10 == 3) 
        {
            // If the digit 3 is found, return 1
            return 1;
        }
        // step over to the next digit to check if it is 3
        d /= 10;
    }
    
    
    return 0;
}

// Function to check if the number is a multiple of 3
int multiple3(int m)
{
    return (m % 3 == 0);
}

int main()
{
    // Taking input from the user
    int num;
    printf("Enter input: ");
    scanf("%d", &num);

    // Check if the number satisfies both the criterias
    if (contains3(num) && multiple3(num))
    {
        // Print "yes" if the number satisfies both the criterias
        printf("yes");
    }
    else
    {
        // Print "no" if the number does not satisfy both the criterias
        printf("no");
    }
       
    return 0;
}
