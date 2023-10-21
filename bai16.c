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

void print_calendar(int year)
{
    int count = 0, first = 0;
    for(int n_month = 1; n_month <= 12; n_month++)
    {
        printf("\nTHANG %d\n", n_month);
        printf("%-3s%-3s%-3s%-3s%-3s%-3s%-3s\n", "S", "M", "T", "W", "T", "F", "S");
        first = All_Sum_Days(1, n_month, year) % 7;
        count = 0;
        for(int k = 0; k < first; k++)
        {
            printf("%-3c", 32);
            count++;
        }
        for(int n_day = 1; n_day <= Day_Of_A_Month(n_month, year);n_day++)
        {

            printf("%-3d", n_day);
            count++;
            if(count % 7 == 0)
            {
                printf("\n");
            }
        }
    }
}
int main()
{
    int year;
    printf("Nhap vao nam can in: ");
    scanf("%d", &year);
    printf("\n");
    print_calendar(year);
}