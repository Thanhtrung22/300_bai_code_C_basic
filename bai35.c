#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool check_prime(int n)
{
    bool flag = 1;
    if(n < 2)
    {
        flag = 0;
    }
    else
    {
        for(int i = 2; i <= sqrt(n); i++)
        {
            if(n % i == 0)
            {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}
int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    if(check_prime(n))
    {
        printf("%d la so prime", n);
    }
    else
    {
        printf("%d khong la so prime", n);
        printf("\nSo prime gan nhat voi %d la: ", n);
        for(int i = n; i >= 2; i--)
        {
            if(check_prime(i))
            {
                printf("%d", i);
                break;
            }
        }
    }
    return 0;
}