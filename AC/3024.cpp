#include <cstdio>
#include <algorithm>
using namespace std;
#define maxsize 10010

int f[maxsize][1005];
int weight[maxsize], value[maxsize];

int main()
{
    int n, m, t = 0, p, w, v, k;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d %d", &p, &w, &v);
        k = 1;
        while (k < p)
        {
            p -= k;
            weight[++t] = w * k;
            value[t] = v * k;
            k <<= 1;
        }
        weight[++t] = w * p;
        value[t] = v * p;
    }
    for (int i = 0; i <= m; ++i)
        f[0][i] = 0;
    for (int i = 0; i <= t; ++i)
        f[i][0] = 0;
    for (int i = 1; i <= t; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (j >= weight[i])
                f[i][j] = max(f[i - 1][j], f[i - 1][j - weight[i]] + value[i]);
            else
                f[i][j] = f[i - 1][j];
        }
    printf("%d", f[t][m]);
    return 0;
}