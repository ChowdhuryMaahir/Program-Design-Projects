// Name: Maahir Azmain Chowdhury
// UID: U46043961
/*Program: A Program to calculate & print the number of
active seconds of an elevator given the arrival times of people*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int active_seconds(int arrival[], int n)
{
    //Initializing the variables
    int activeSeconds = 0;
    int i = 0;
    int diff = 0;
    int *arrivalPtr = arrival;

    //Running a loop to check whether the differences are greater or less than 10
    for (i = 0; i < n-1; i++)
    {
        //Calculating the difference
        diff = *(arrivalPtr + i + 1) - *(arrivalPtr + i);
        if (diff >= 10)
        {
            //Add 10 seconds if difference is greater or equal to 10
            activeSeconds += 10;
        }
        else if (diff < 10)
        {
            //Add the difference if the difference is less than 10
            activeSeconds += diff;
        }
    }

    //Add 10 seconds at the end to add the 10 seconds for the last arrival time
    activeSeconds += 10;

    return activeSeconds;
}

int main()
{
    //Initializing the number of people counter
    int numOfPeople;

    //Taking input for the number of people
    printf("Enter number of people: ");
    scanf("%d", &numOfPeople);

    //Initializing the array to store the arrival times    
    int arrival[numOfPeople]; 

    //Taking input for the arrival times and storing it in the array
    printf("Enter arrival times: ");
    for (int i = 0; i < numOfPeople; i++)
    {
        scanf("%d", &arrival[i]);
    }

    //Printing out the number of active seconds after calling the function
    printf("Active seconds: %d", active_seconds(arrival, numOfPeople));
    return 0;
}