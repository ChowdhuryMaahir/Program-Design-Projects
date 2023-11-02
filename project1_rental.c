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

    int rates[4][3] ={
        {7, 10, 40},
        {27, 39, 156},
        {61, 87, 348},
        {59, 84, 336}
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
    
    //Selecting the correct rates according to the user input
    if (equipNum < 2)
        {
            weeklyCharge = rates[0][2];
            dailyCharge = rates[0][1];
            hourlyCharge = rates[0][0];
        }
    else if (equipNum > 1 && equipNum < 3)
        {
            weeklyCharge = rates[1][2];
            dailyCharge = rates[1][1];
            hourlyCharge = rates[1][0];
        }
    else if (equipNum > 2 && equipNum < 4)
        {
            weeklyCharge = rates[2][2];
            dailyCharge = rates[2][1];
            hourlyCharge = rates[2][0];
        }
    else if (equipNum > 3)
        {
            weeklyCharge = rates[3][2];
            dailyCharge = rates[3][1];
            hourlyCharge = rates[3][0];
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
    charges = (numDays * dailyCharge) + (numWeeks * weeklyCharge) + (numHours * hourlyCharge);
    
    //Displaying the output
    printf("Charge($): %d", charges);

    return 0;
}