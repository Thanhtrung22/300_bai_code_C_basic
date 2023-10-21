#include <stdio.h>
#include <stdbool.h>

bool check_year(int year)
{
    bool flag = 0;
    if((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
    {
        flag = 1;
    }
    return flag;
}
int Day_Of_A_Year(int year)
{
    int day = 0;
    if(check_year(year))
    {
        day = 366;
    }
    else
    {
        day = 365;
    }
    return day;
}

int Sum_Day_Of_Years(int year)
{
    int day = 0;
    for(int i = 1; i < year; i++)
    {
        day += Day_Of_A_Year(i);
    }
    return day;
}

int Day_Of_A_Month(int month, int year)
{
    int day = 0;
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        {
            day = 31;
            break;
        }
        case 2:
        {
            if(check_year(year))
            {
                day = 29;
            }
            else
            {
                day = 28;
            }
            break;
        }
        default:
        {
            day = 30;
            break;
        }
    }
    return day;
}

int Day_Of_Months(int month, int year)
{
    int day = 0;
    for(int i = 1; i < month; i++)
    {
        day += Day_Of_A_Month(i, year);
    }
    return day;
}

int All_Sum_Days(int day ,int month, int year)
{
    int sum = 0;
    sum = day + Day_Of_Months(month, year) + Sum_Day_Of_Years(year);
    return sum;
}

void display_result(int day, int month, int year)
{
    int sum = 0;
    sum = All_Sum_Days(day, month, year);
    switch(sum % 7)
    {
        case 0: printf("Ngay %02d/%02d/%02d la chu nhat", day, month, year); break;
        case 1: printf("Ngay %02d/%02d/%02d la thu hai", day, month, year); break;
        case 2: printf("Ngay %02d/%02d/%02d la thu ba", day, month, year); break;
        case 3: printf("Ngay %02d/%02d/%02d la thu tu", day, month, year); break;
        case 4: printf("Ngay %02d/%02d/%02d la thu nam", day, month, year); break;
        case 5: printf("Ngay %02d/%02d/%02d la thu 6", day, month, year); break;
        case 6: printf("Ngay %02d/%02d/%02d la thu bay", day, month, year); break;
    }
}

int main()
{
    int day , month, year;
    day = 12, month = 10, year = 2023;
    display_result(day, month, year);
}