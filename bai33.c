#include <stdio.h>
#include <math.h>
int count_num(int n)
{
    int count = 0;
    while(n > 0)
    {
        count++;
        n /=  10;
    }
    return count;
}
int check_Armstrong(int n)
{
    int flag = 0;
    int sum = 0;
    int temp = n;
    int last = 0;
    int count = count_num(n);
    while(temp > 0)
    {
        last = temp % 10;
        sum += pow(last, count);
        temp /= 10;
    }
    if(sum == n)
    {
        flag = 1;
    }
    return flag;
}
void  In_So_Armstrong()
{
    printf("Danh sach so Armstrong co 3 hoac 4 chu so:\n");
    for(int i = 100; i < 9999; i++)
    {
        if(check_Armstrong(i))
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    In_So_Armstrong();
    return 0;
}