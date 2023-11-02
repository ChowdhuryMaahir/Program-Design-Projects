// Name: Maahir Azmain Chowdhury
// UID: U46043961
/*Program: A Program to decode the text from an input file and store it in the output file*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function prototype
void decode(char words[][101], int num_words, char *result);

int main() {
    
    // Initialize the variable to store the name of the input file and take input for the name of the input file
    char inFile[101];
    scanf("%s", inFile);

    // Initialize and add the required prefix in the output file name
    char outFile[201]; 
    strcpy(outFile, "decoded_");
    strcat(outFile, inFile);

    // Initialize the pointer for the input file
    FILE *pInFile;
    
    // Initialize the array to store the decoded text
    char resultFile[1001];

    // Initialize the word array to store the text from the input file
    char words[1000][101];

    // Initialize the word counter
    int num_words = 0; 

    // Open the the input file to read
    pInFile = fopen(inFile, "r");

    // If the input file is empty return 1
    if (pInFile == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read the words from the input file and store the number of words in num_words
    while (fscanf(pInFile, "%100s", words[num_words]) == 1) {
        num_words++;
    }

    // Close the input file
    fclose(pInFile);

    // Call the function to decode the text
    decode(words, num_words, resultFile);

    // Open the output file and store the text in the file
    FILE *pOutFile = fopen(outFile, "w");
    fprintf(pOutFile, "%s", resultFile);
    
    // Close the output file
    fclose(pOutFile);

    // print the name of the output file
    printf("Output file name:\n%s\n", outFile);

    return 0;
}

void decode(char words[][101], int num_words, char *result) {

    // Loop through the text and avoid the white spaces while storing the first character of the words
    for (int i = 0; i < num_words; i++) {
        if (words[i][0] != ' ' && words[i][0] != '\n' && words[i][0] != '\t') {
            
            // Store the required character in the result array using the pointer
            *result = words[i][0]; 
            
            // Move the pointer to the next position
            result++; 
        }
    }
    
    // Add the NULL character at the end of the text
    *result = '\0'; 
}
