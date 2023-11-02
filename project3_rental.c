// Name: Maahir Azmain Chowdhury
// UID: U46043961
/*Program: A Program to calculate & print the charges
for a floor cleaning equipment rental*/


#include <stdio.h>
#include <stdlib.h>


int main()
{
    //Declaring & initializing the variables
    int charges = 0;
    int weeklyCharge = 0;
    int dailyCharge = 0;
    int hourlyCharge = 0;
    int numHours = 0;

    //Declaring an array to store all the rates
    int rates[4][3] ={
        /*4-hours,  Per day,    Per week*/
        {7, 10, 40},                    //Equipment 1
        {27, 39, 156},                  //Equipment 2
        {61, 87, 348},                  //Equipment 3
        {59, 84, 336}                   //Equipment 4
    };
    
    //Telling the user to select from 4 equipments
    printf("Please select from four equipment: 1, 2, 3, and 4\n");
    
    //Taking "equipment" input from the user
    int equipNum;
    printf("Enter equipment selection: ");
    scanf("%d", &equipNum);
    
    //Validating the equipment number input
    if (equipNum > 4 || equipNum < 1)
    {
        printf("Invalid selection. Select from 1 to 4.");
        exit(0);
    }

    //Taking "days" input from the user
    int days;
    printf("Enter days: ");
    scanf("%d", &days);
    
    //Taking "hours" input from the user and Validating the input
    int hours;
    printf("Enter hours: ");
    scanf("%d", &hours);
    if (hours >= 24 || hours < 0)
    {
        printf("Invalid hours.");
        exit(0);
    }

    /*Charging hourly rate if the "hours" input is less than or equal to 4
    And charging daily rate if "hours" input is greater than 4*/
    if (hours <= 4)
    {
        numHours = 1;
    }
    else if (hours > 4)
    {
        numHours = 0;
        days += 1;
    }
    
    /*Initializing the week counting variable & calculating 
    the number of weeks if "days" is greater than 7*/
    int numWeeks;
    numWeeks = days / 7;

    /*Initializing the days counting variable & calculating the number of 
    days if "days" is greater than 7 after counting the number of weeks*/
    int numDays = 0;
    if (days > 7)
    {
        numDays = days % 7;
    }


    //Adding the number of days to the "numDays" counter if days is less than or equal to 3
    if (days <= 3)
    {
        numDays += days;   
    }
    //Incrementing the "numWeeks" counter if days is more than 3 to charge weekly rate
    else if (days >= 4 && days <=7)
    {
        numWeeks += 1;
    }
    // Incrementing the "numWeeks" counter if "numDays" counter is more than 3
    else if (numDays > 3)
    {
        numWeeks += 1;
        numDays = 0;
    }
    
    
    //Calculating the charges
    charges = (numDays * rates[equipNum-1][1]) + (numWeeks * rates[equipNum-1][2]) + (numHours * rates[equipNum-1][0]);
    
    //Displaying the output
    printf("Charge($): %d", charges);

    return 0;
}