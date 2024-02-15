#include <stdio.h>

int count_odd(int *arr, int arrSz)
{
    int odd = 0;
    for (int i = 0; i < arrSz; i++)
    {
        if (arr[i] % 2 != 0)
        {
            odd++;
        }
    }

    return odd;
}

int main()
{

    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d", count_odd(arr, n));

    return 0;
}