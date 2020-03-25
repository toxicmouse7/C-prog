#include <stdio.h>
#include <stdlib.h>
#define M_PI 3.14159265358979323846

int Simple(int N)
{
    for (int i = 2; i * i <= N; i++)
        if (N % i == 0) return 0;
    return 1;
}

int main()
{
   scanf_s
}