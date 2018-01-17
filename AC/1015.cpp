#include <iostream>
#include <algorithm>
using namespace std;

int product(int a[], int b[], int res[], int lenA, int lenB)
{
    int lenofres = 0, i, j;
    lenofres = lenA + lenB - 1;
    for (i = 0; i < lenA; ++i)
        for (j = 0; j < lenB; ++j)
        {
            res[i + j] += a[lenA - 1 - i] * b[lenB - 1 - j];
            if (res[i + j] > 2000000000)
            {
                res[i + j + 1] += res[i + j] / 10;
                lenofres = max(lenofres, i + j + 1);
                res[i + j] = res[i + j] % 10;
            }
        }
    i = 0;
    while (i < lenofres)
    {
        j = res[i] / 10;
        if (j > 0)
        {
            res[i + 1] += j;
            lenofres = max(lenofres, i + 2);
        }
        res[i] = res[i] % 10;
        ++i;
    }
    return lenofres;
}

int main()
{
    int a[310], b[310], res[620] = {0};
    int lenA = 0, lenB = 0, lenofres;
    char c;
    while ((c = cin.get()) != '\n')
    {
        a[lenA] = c - '0';
        ++lenA;
    }
    while ((c = cin.get()) != '\n')
    {
        b[lenB] = c - '0';
        ++lenB;
    }
    lenofres = product(a, b, res, lenA, lenB);
    for (int i = lenofres - 1; i >= 0; --i)
        cout << res[i];
    return 0;
}