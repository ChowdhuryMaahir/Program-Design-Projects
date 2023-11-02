// Name: Maahir Azmain Chowdhury
// UID: U46043961
/*Program: A Program to determine if the input characters(alphabet) are in order*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    // Initialization the variable to store & compare previous character
    char charPrev;
    // Initialization the variable to store & compare next character
    char charCurr;
    // Initialization of flag variable
    int true = 1;

    // Displaying the input prompt
    printf("Enter input: ");

    //Infinite loop to continuously take character inputs
    while (1)
    {
        // Taking input of the next character
        charCurr = getchar();

        // Breaking out of the loop if the user press "enter" button
        if (charCurr == '\n')
        {
            break;
        }
        
        // Converting all the characters to lowercase for efficient comparison
        charCurr = tolower(charCurr);

        // Validating the input characters to only alphabets
        if (!isalpha(charCurr))
        {
            printf("invalid input");
            return 0;
        }
        
        // Comparing the current character with the previous character
        if (charCurr < charPrev)
        {
            /* Flag variable set to "0" if the condition is met and the current character
            is less than the previous character*/
            true = 0;
        }

        // Storing the current character in the charPrev variable for next comparison
        charPrev = charCurr;
    }

    // Displaying the correct message according to the value of the flag variable
    if (true)
    {
        printf("in order");
    }
    else
    {
        printf("not in order");
    }
    
    return 0;
}