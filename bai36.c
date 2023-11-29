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

void In_So_Nguyen_To(int n)
{
    int i = 2;
    int count = 0;
    printf("%d so nguyen to dau tien la: ", n);
    while(count < n)
    {
        if(check_prime(i))
        {
            printf("%d ", i);
            count++;
        }
        i++;
        
    }
}
int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    In_So_Nguyen_To(n);
    return 0;
}