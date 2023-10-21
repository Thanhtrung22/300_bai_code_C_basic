#include <stdio.h>

typedef struct
{
    int week;
    int day;
    int hour;
}Time;

Time Convert_Time(int hours)
{
    Time time;
    time.week = hours / (24 * 7);
    time.day = hours % (24 * 7) / 24;
    time.hour = hours % (24 * 7) % 24;
    return time;
}

int main()
{
    Time time;
    int hours;
    printf("Nhap vao so gio: ");
    scanf("%d", &hours);
    time = Convert_Time(hours);
    printf("%d weeks: %d days: %d hours", time.week, time.day, time.hour);
    return 0;
}