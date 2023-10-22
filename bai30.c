#include <stdio.h>
#include <math.h>

void Gui_Tiet_kiem(float tien_goc, float lai_suat, int nam )
{
    float sum = 0.0f;
    lai_suat = lai_suat / 100;
    printf("\n%-8s %-10s\n", "Year", "Money");
    for(int i = 1; i <= nam; i++)
    {
        sum = tien_goc * pow((1 + lai_suat), i);
        printf("%-8d %-10.1f\n", i, sum);
    }
}

int main()
{
    float tien_goc = 0, lai_suat = 0;
    int year = 0;
    printf("Nhap tien goc, lai suat va so nam: ");
    scanf("%f,%f,%d", &tien_goc, &lai_suat, &year);
    printf("\nLai suat: %.1f%%", lai_suat);
    printf("\nTien goc: %.1f", tien_goc);
    printf("\nThoi han: %d", year);
    Gui_Tiet_kiem(tien_goc, lai_suat, year);
    return 0;

}