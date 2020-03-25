#include <stdio.h>
#include <stdlib.h>

int Simple(int N)
{
    for (int i = 2; i * i <= N; i++)
        if (N % i == 0) return 0;
    return 1;
}

int main()
{
    int* ans, *quest;
    int count = 0, k, simp = 2;
    scanf_s("%d", &k);
    ans = (int*)calloc(k, sizeof(int));
    quest = (int*)calloc(k, sizeof(int));
    for (int i = 0; i < k; i++)
    {
        scanf_s("%d", &quest[i]);
    }

    for (int i = 0; i < k; i++)
    {
        while (count != quest[i])
        {
            if (Simple(simp) == 1)
            {
                count++;
                simp++;
            }
            else simp++;
        }
        ans[i] = simp;
        count = 0;
        simp = 2;
    }

    for (int i = 0; i < k; i++)
    {
        printf("%d\n", ans[i]-1);
    }
}