#include <stdio.h>

void Phan_Tich_Thua_So(int n)
{
    int i = 0, count = 0;
    for(int i = 2; i <= n; i++)
    {
        count = 0;
        while(n % 2 == 0)
        {
            count++;
            n /= i;
        }
        if(count)
        {
            if(count > 1)
            {
                printf("%d^%d", i, count);
            }
            else
            {
                printf("%d", i);
            }
        }
        if(n > 1)
        {
            printf(" * ");
        }
    }
}

int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("Thua so nguyen to cua %d la:\n", n);
    Phan_Tich_Thua_So(n);
    return 0;
}