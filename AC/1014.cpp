#include <iostream>
#include <string.h>
using namespace std;
#define Max_size 100005

void add(char *a, char *b, char *res)
{
    int lenA = strlen(a), lenB = strlen(b);
    int count, jinwei = 0;
    count = lenA > lenB ? lenA : lenB;
    res[count + 1] = '\0';
    while (lenA > 0 || lenB > 0)
    {
        if (lenA > 0 && lenB > 0)
        {
            res[count] = a[lenA - 1] + b[lenB - 1] - '0' - '0' + jinwei;
            jinwei = int(res[count]) / 10;
            res[count] = res[count] % 10 + '0';
            --count;
            --lenA;
            --lenB;
        }
        else
        {
            if (lenA > 0 && lenB <= 0)
            {
                res[count] = a[lenA - 1] - '0' + jinwei;
                jinwei = int(res[count]) / 10;
                res[count] = res[count] % 10 + '0';
                --count;
                --lenA;
            }
            else
            {
                if (lenA <= 0 && lenB > 0)
                {
                    res[count] = b[lenB - 1] - '0' + jinwei;
                    jinwei = int(res[count]) / 10;
                    res[count] = res[count] % 10 + '0';
                    --count;
                    --lenB;
                }
            }
        }
    }
    count = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
    if (jinwei > 0)
    {
        res[0] = '1';
    }
    else
    {
        for (int k = 0; k < count + 1; ++k)
        {
            res[k] = res[k + 1];
        }
    }
}

int main()
{
    char a[Max_size], b[Max_size], res[Max_size];
    char c;
    int i = 0;
    while ((c = cin.get()) != '\n')
    {
        a[i] = c;
        ++i;
    }
    a[i] = '\0';
    i = 0;
    while ((c = cin.get()) != '\n')
    {
        b[i] = c;
        ++i;
    }
    b[i] = '\0';
    add(a, b, res);
    cout << res;
    return 0;
}