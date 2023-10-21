#include <stdio.h>

typedef struct
{
    int second;
    int minute;
    int hour;
}Time;

Time For_Time(Time time1, Time time2)
{
    Time result;
    int total_seconds = 0;
    total_seconds = 3600 * time1.hour + 60 * time1.minute + time1.second;
    total_seconds -= 3600 * time2.hour + 60 * time2.minute + time2.second;
    if(total_seconds < 0)
    {
        total_seconds = -total_seconds;
    }
    result.hour = total_seconds / 3600;
    result.minute = total_seconds % 3600 / 60;
    result.second = total_seconds % 3600 % 60;
    return result;
}
void enter(Time *time)
{
    printf("Nhap vao gio, phut, giay: ");
    scanf("%d%d%d", &time->hour, &time->minute, &time->second);
}
void display(Time time)
{
    printf("%d hour: %d minute: %d second", time.hour, time.minute, time.second);
}
int main()
{
    Time time1, time2;
    enter(&time1);
    enter(&time2);
    Time result = For_Time(time1, time2);
    printf("Khoang thoi gian giua 2 thoi diem la:\n");
    display(result);
    return 0;

}