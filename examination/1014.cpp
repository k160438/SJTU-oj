#include <iostream>
#include <cstring>
using namespace std;
#define maxsize 100005

char a[maxsize], b[maxsize];
int res[maxsize] = {0};

int main()
{
    int lenA, lenB, i;
    int lenSum = 0;
    cin >> a >> b;
    lenA = strlen(a);
    lenB = strlen(b);
    while (lenA > 0 && lenB > 0)
    {
        res[lenSum++] = a[--lenA] + b[--lenB] - 2 * '0';
    }
    if (lenA > 0)
    {
        while (lenA > 0)
        {
            res[lenSum++] = a[--lenA] - '0';
        }
    }
    else
    {
        while (lenB > 0)
        {
            res[lenSum++] = b[--lenB] - '0';
        }
    }

    i = 0;
    while (i < lenSum)
    {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
        ++i;
    }
    if (res[i] > 0)
    {
        cout << res[i];
    }
    --i;
    while (i >= 0)
    {
        cout << res[i--];
    }
    return 0;
}