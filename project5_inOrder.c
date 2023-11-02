// Name: Maahir Azmain Chowdhury
// UID: U46043961
/*Program: A Program to determine if the input characters(alphabet) are in order*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function prototype
int inOrder(char *input);

int main(int argc, char *argv[])
{
    // Validating the number of arguments to be passed
    if (argc != 2)
    {
        printf("invalid input");
        return 1;
    }

    // Initializing the return value
    int returnVal = 0;

    // Assigning the value of the 2nd element of argv to the inputPtr
    char *inputPtr = argv[1];

    // Running the function and assigning its return value to the return value
    returnVal = inOrder(inputPtr);

    // Printing the result according to the output of the function
    if (returnVal == 1)
    {
        printf("in order");
    }
    else if (returnVal == 0)
    {
        printf("not in order");
    }
    else if (returnVal == -1)
    {
        printf("invalid input");
    }

    return 0;
}

int inOrder(char *input)
{
    // Initializing the pointer to point to the input value
    char *inptPtr1 = input;

    int charPrev = *inptPtr1;
    
    // Initialization of flag variable
    int isTrue = 1;

    // Checking if the input characters are digit
    while (*inptPtr1 != '\0')
    {
        if (isdigit(*inptPtr1))
        {
            isTrue = -1;
            return isTrue;
        }

        break;

        inptPtr1++;
    }

    // Assigning the first value of input to the pointer variable
    inptPtr1 = input; 

    // Checking if the characters are in order
    while (*inptPtr1 != '\0')
    {
        if (*inptPtr1 < charPrev)
        {
            isTrue = 0;
            return isTrue;
        }

        charPrev = *inptPtr1;
        inptPtr1++;
    }

    // returning the value
    return isTrue;
}
