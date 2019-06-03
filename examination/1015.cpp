#include <iostream>
#include <cstring>
using namespace std;
#define maxsize 1000

char a[maxsize], b[maxsize];
int res[maxsize] = {0};

int main()
{
    int lenA, lenB;
    int i, j, k;
    cin >> a >> b;
    lenA = strlen(a);
    lenB = strlen(b);
    for (j = 1; j <= lenA; ++j)
        for (k = 1; k <= lenB; ++k)
        {
            res[j + k - 2] += (a[lenA - j] - '0') * (b[lenB - k] - '0');
        }
    i = 0;
    while (i < lenA + lenB - 2 || res[i] > 9)
    {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
        ++i;
    }
    while (res[i] > 9)
    {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
        ++i;
    }
    while (i >= 0)
    {
        cout << res[i--];
    }
    return 0;
}