#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, l, r, mid;
    int **data;
    char tmp;
    bool flag;
    scanf("%d %d", &n, &m);
    scanf("%c", &tmp);
    data = new int *[n + 1];
    for (int i = 0; i < n + 1; ++i)
        data[i] = new int[m + 1];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%c", &tmp);
            if (tmp == 'X')
                data[i][j] = 1;
            else
                data[i][j] = 0;
        }
        scanf("%c", &tmp);
    }

    for (int i = 1; i < n; ++i)
        data[i][0] += data[i - 1][0];
    for (int i = 1; i < m; ++i)
        data[0][i] += data[0][i - 1];
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];

    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < m; ++j)
    //         printf("%d ", data[i][j]);
    //     printf("\n");
    // }

    l = 0;
    r = min(n, m >> 1);
    while (l < r)
    {
        mid = ((l + r) >> 1) + 1;
        flag = false;
        if (!data[mid - 1][(mid << 1) - 1])
            flag = true;
        else
        {
            for (int i = mid; i < n; ++i)
                if (data[i][(mid << 1) - 1] == data[i - mid][(mid << 1) - 1])
                {
                    flag = true;
                    break;
                }
            if (!flag)
                for (int i = mid * 2; i < m; ++i)
                    if (data[mid - 1][i] == data[mid - 1][i - (mid << 1)])
                    {
                        flag = true;
                        break;
                    }
            if (!flag)
                for (int i = mid; i < n; ++i)
                    for (int j = mid * 2; j < m; ++j)
                        if (data[i][j] + data[i - mid][j - (mid << 1)] == data[i][j - (mid << 1)] + data[i - mid][j])
                        {
                            flag = true;
                            break;
                        }
        }
        if(flag)
            l = mid;
        else
            r = mid - 1;
    }
    printf("%d", r*r*2);
    return 0;
}