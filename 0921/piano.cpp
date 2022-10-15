#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <windows.h>

int calc_frequency(int octave, int inx);
int main(void)
{
    int sheet[] = { 7, 7, 9, 9, 7, 7, 4, 7, 7, 4, 4, 2, 7, 7, 9, 9, 7, 7, 4, 7, 4, 2, 4, 0 };
    for (int i = 0; i < sizeof(sheet) / sizeof(int); ++i) {
        Beep(calc_frequency(4, int(sheet[i])), 500);
    }
}

int calc_frequency(int octave, int inx)
{
    double do_scale = 32.7032;
    double ratio = pow(2., 1 / 12.), temp;
    int i;
    temp = do_scale * pow(2, octave - 1);
    for (i = 0; i < inx; i++) {
        temp = (int)(temp + 0.5);
        temp *= ratio;
    }
    return (int)temp;
}

