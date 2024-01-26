//std id=2200003366
//name-surname= Saadet Elizaveta BABAL
//In this project, I wanted to write a program that finds what the next day is from the dates entered by the user.
#define _CRT_SECURE_NO_WARNINGS//Here i used this statement to avoid problems with scanfs.
#include <stdio.h>//Here i included stdio.h to use the library under header file.
#include <stdbool.h>//I added it to be able to use the functions under the bool file.
struct date //I created struct for year month and day as requested in the assignment.
{
    int month;
    int day;
    int year;
};

int day_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//I created an array as an integer in order to use the array elements given in the assignment.

struct date tomorrow(struct date day);//I defined the desired tomorrow function in the assignment.
bool is_leap_year(struct date day);//I defined the desired is_leap_year function in the assignment.

int main()//I created the main function to get information from the user and give information to the user.
{
    struct date input, output;
    printf("Enter a date (mm dd yyyy): ");
    scanf("%d %d %d", &input.month, &input.day, &input.year);
    output = tomorrow(input);//I assigned the inputs of the tomorrow array as output to be able to print to the user.
    printf("Tomorrow's date is %d/%d/%02d.\n", output.month, output.day, output.year%100);//I used printf to print the information, and I took the mode according to the number 100 to print the last two digits of the year.
    return 0;
}

struct date tomorrow(struct date day)//In order to process the information I will give as output, I created the tomorrow function as requested in the assignment.
{
    struct date next_day;
    int days_in_month;
    if (day.month == 12 && day.day == 31)//I used the if else structure to calculate the next day of the month and days entered by the user.
    {
        next_day.month = 1;//If the user enters the last day of the year, the next day will be new year, so I prepared a separate if structure.
        next_day.day = 1;
        next_day.year = day.year + 1;
    }
    else
    {
        days_in_month = day_in_month[day.month - 1];//I assigned it to be able to determine the number of days of the selected month.
        if (day.month == 2 && is_leap_year(day))//If the user enters February, I prepared a separate if so that the number of days is 29.
        {
         
            days_in_month = 29;//I set the number of days in February to 29 as requested in the assignment.
        }
        if (day.day == days_in_month)//If the day entered by the user is the last day of the month, I have prepared a separate if to switch to the first day of the next month.
        {

            next_day.month = day.month + 1;
            next_day.day = 1;//In order to advance to the first day of the next month, I assigned 1 to the next day expression.
            next_day.year = day.year;
        }
        else
        {
          
            next_day.month = day.month;//I used else as the last possibility, in case none of the above exceptions exist on the dates the user entered.
            next_day.day = day.day + 1;
            next_day.year = day.year;
        }
    }
    return next_day;
}

bool is_leap_year(struct date day)//I created this function to find the leap year as requested in the assignment.
{
    if (day.year % 400 == 0)//In order to make February 29, which is normally 28 days, we need to separate the leap years from the normal years, so I divided the number of years by 400 to find out if there is a leap year.
    {
        return true;//I returned the loop as true because if it is a multiple of 4 it will be a leap year.
    }
    else if (day.year % 100 == 0)//I returned false because there will be no leap year if the remainder is zero when divided by one hundred.
    {
        return false;
    }
    else if (day.year % 4 == 0)//I returned the function as true, since when divided by four, if there is no remainder, it will be a leap year.
    {
        return true;
    }
    else
    {
        return false;//I returned the function as false, since if all conditions are not met, there cannot be a leap year anyway.
    }
}