#include <stdio.h>

float F(float a, float b, int c)
{
    switch(c)
    {
        case 0: return a + b; break;
        case 1: return a - b; break;
        case 2: return a * b; break;
        case 3: return a / b; break;
    }

}

int main()
{
    char sign[] = {'+', '-', '*', '/'};
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                for(int m = 0; m < 4; m++)
                {
                    for(int l = 0; l < 4; l++)
                {
                    if(F(F(F(F(F(1, 2, i), 3, j), 4, k), 5, m), 6, l) == 36)
                    {
                        printf("((((1 %c 2) %c 3) %c 4) %c 5) %c 6 == 36\n", sign[i], sign[j], sign[k], sign[m], sign[l]);
                    }
                }
                }
                
            }
        }
    }
}