#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void sap_xep_tang(int *a, int *b, int *c)
{
    
    if(*a > *b)
    {
        swap(a, b);
    }
    if(*b > *c)
    {
        swap(b, c);
    }
    if(*a > *c)
    {
        swap(a, c);
    }
}

int main()
{
    int a = 9, b = 7, c = 8;
    printf("Truoc khi sap xep: %d %d %d\n", a, b, c);
    sap_xep_tang(&a, &b, &c);

    printf("Sau khi sap xep: %d %d %d\n", a, b, c);
}