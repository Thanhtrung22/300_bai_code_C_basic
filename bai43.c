#include <stdio.h>

int Fibo_n(int n)
{
    if(n <= 0)
    {
        return -1;
    }
    if(n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        int fib1 = 1, fib2 = 1;
        int result = 0, count = 0;
        int i = 3;
        while(i <= n)
        {
            result = fib1 + fib2;
            fib1 = fib2;
            fib2 = result;
            i++;
        }
        return result;
    }
}

int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("So fibo thu %d la %d", n, Fibo_n(n));
    return 0;
}