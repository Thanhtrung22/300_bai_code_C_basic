#include <stdio.h>
#include <math.h>

typedef struct
{
    int tuSo;
    int mauSo;
}Phan_So;

int UCLN(int a, int b)
{
    int ucln = 0;
    if(a == 0)
    {
        ucln = b;
    }
    else
    {
        int min = 0;
        min = a < b ? a : b;
        for(int i = 1; i <= abs(min); i++)
        {
            if((a % i == 0) && (b % i == 0))
            {
                ucln = i;
            }
        }
    }
    
    return ucln;
}
void enter_data(Phan_So *p)
{
    printf("Nhap tu so: ");
    scanf("%d", &p->tuSo);
    do
    {
        printf("Nhap mau so: ");
        scanf("%d", &p->mauSo);
    }while(p->mauSo == 0);
    
}
void rut_gon(Phan_So *p)
{
    
    int ucln = 0;
    ucln = UCLN(p->tuSo, p->mauSo);
    p->tuSo  /= ucln;
    p->mauSo /= ucln; 
}
void display(Phan_So p)
{
    if(p.mauSo == 1 || p.mauSo == -1)
    {
        if(p.tuSo < 0 && p.mauSo < 0)
        {
            printf("%d ", -p.tuSo);
        }
        else
        {
            printf("%d ", p.tuSo);
        }
    }
    else
    {
        if(p.tuSo < 0 && p.mauSo < 0)
        {
            printf("%d / %d", -p.tuSo, -p.mauSo);
        }
        else
        {
            printf("%d / %d", p.tuSo, p.mauSo);
        }
    }
}

int main()
{
    Phan_So p;
    
    enter_data(&p);
    printf("Phan so truoc khi rut gon la: ");
    display(p);
    rut_gon(&p);

    printf("\nPhan so sau khi rut gon la: ");
    display(p);
    return 0;
}