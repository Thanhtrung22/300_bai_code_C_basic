#include <stdio.h>
#include <stdbool.h>

int Sum(int n)
{
    int sum = 0;
    while(n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool check(char *s)
{
    bool flag = 0;
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < 8; i++)
    {
        if(i % 2 == 0)
        {
            sum1 += (s[i] - '0');
        }
        if(i % 2 == 1)
        {
            int temp = s[i] - '0';
            temp *= 2;
            sum2 += Sum(temp);
        }
    }
    if((sum1 + sum2 + (s[8] - '0')) % 10 == 0)
    {
        flag = 1;
    }
    return flag;
}

int main()
{
    char SIN[10];
    printf("\nNhap chuoi can kiem tra: ");
    fflush(stdin);
    fgets(SIN, sizeof(SIN), stdin);
    if(check(SIN))
    {
        printf("\nChuoi hop le");
    }
    else
    {
        printf("\nChuoi khong hop le");
    }
    return 0;
}