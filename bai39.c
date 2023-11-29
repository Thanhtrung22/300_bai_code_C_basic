#include <stdio.h>
#include <math.h>

void In_Pytago()
{
    for(int i = 1; i < 100; i++)
    {
        if(((i+ 1) - (i -1) == 2))
        {
            if(pow((i -1), 2) + pow(i, 2) == pow((i + 1), 2))
            {
                printf("(%d, %d, %d)\n", i -1, i, i + 1);
            }
        }
        if(((i + 2) - (i - 2) == 4) && (i % 2 == 0))
        {
            if(pow((i - 2), 2) + pow(i, 2) == pow((i + 2), 2))
            {
                printf("(%d, %d, %d)\n", i - 2, i, i + 2);
            }
        }
    }
}
int main()
{
    In_Pytago();
    return 0;
}