#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int day;
    int month;
    int year;
}Date;

bool check_year(int year)
{
    bool flag = 0;
    if((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
    {
        flag = 1;
    }
    return flag;
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

void next_day(Date present, Date *next_Date)
{
    next_Date->day = (present.day % Day_Of_A_Month(present.month, present.year)) + 1;
    next_Date->month = present.month;
    if(next_Date->day == 1)
    {
        next_Date->month = (present.month % 12) + 1;
    }
    
    next_Date->year = present.year;
    if(next_Date->month == 1 && next_Date->day == 1)
    {
        next_Date->year = present.year + 1;
    }
}   

void previous_day(Date current, Date *previous)
{
    *previous = current;
    if(current.day > 1)
    {
        previous->day = current.day - 1;
        
    }
    else
    {
        if(current.month == 1)
        {
            previous->month = 12;
            previous->year = current.year - 1;
             previous->day = Day_Of_A_Month(previous->month, previous->year);
        }
        else
        {
            previous->month = current.month - 1;
            previous->day = Day_Of_A_Month(previous->month, previous->year);
        }
       
    }
}
int main()
{
    Date current, next_date, previous_date;
    do
    {
        printf("Nhap vao ngay thang nam: ");
        scanf("%d%d%d", &current.day, &current.month, &current.year);
    } while (current.day > Day_Of_A_Month(current.month, current.year) || current.day <= 0 || current.month > 12 || current.month <= 0);
    
    
    next_day(current, &next_date);
    printf("\nNgay hom sau la: %02d/%02d/%02d", next_date.day, next_date.month, next_date.year);
    previous_day(current, &previous_date);
    printf("\nNgay hom qua la: %02d/%02d/%02d", previous_date.day, previous_date.month, previous_date.year);
    return 0;
}