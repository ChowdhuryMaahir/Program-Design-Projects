// Name: Maahir Azmain Chowdhury
// UID: U46043961
/*Program: A Program that uses an encoding algorithm to
compress the repeating letters in a word*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char *input, char *output);

int main()
{
    // Initializing both the input array and the output array
    char inStr[1000];
    char outStr[1000];

    // Prompting the user to input a string to be compressed
    printf("Enter message: ");
    scanf("%s", inStr);

    /* Calling the encoding function to compress the
       string and storing it in the output array*/
    compress(inStr, outStr);

    // Displaying the compressed word
    printf("Output: %s", outStr);
}


void compress(char *input, char *output)
{
    // Initializing pointers to point towards the array
    char *inStrPtr = input;
    char *outStrPtr = output;

    /* Running a while loop to check all the characters in
       the word until the "null character" is reached*/
    while (*inStrPtr != '\0')
    {
        // initializing a char variable to store each character in the word
        char currChar = *inStrPtr;

        // Initializing a counter variable to keep count of the repeating characters
        int charCounter = 1;

        // Running a while loop to count the repeating characters
        while (*(inStrPtr + 1) == currChar)
        {
            charCounter++;
            inStrPtr++;
        }

        /* If more than 2 repeating character is found,
           compress the group of  repeating characters*/
        if (charCounter > 2)
        {
            *outStrPtr = (char)(charCounter + '0');
            outStrPtr++;
        }

        /* If the character is only repeated once,
           it is not compressed*/
        else if (charCounter == 2)
        {
            // Adding the character twice in the output array
            for (int i = 0; i < 1; i++)
            {
                *outStrPtr = currChar;
                outStrPtr++;
            }  
        }

        // Adding the character in the output array if it is not repeated
        *outStrPtr = currChar;
        outStrPtr++;     

        // Checking the next character in the word
        inStrPtr++;
    }

    // Terminate the output string
    *outStrPtr = '\0';
}