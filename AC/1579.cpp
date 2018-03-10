#include <cstdio>
#include <algorithm>
using namespace std;
#define maxsize 1003

int f[maxsize][maxsize] = {0};

int main()
{
    int n, m, ans = 0;
    char x[maxsize], y[maxsize];
    scanf("%d %d", &n, &m);
    scanf("%s", x);
    scanf("%s", y);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (x[i - 1] == y[j - 1])
                f[i][j] = max(f[i - 1][j - 1] + 1, max(f[i][j - 1], f[i - 1][j]));
            else
                f[i][j] = max(f[i][j - 1], f[i - 1][j]);
            if (ans < f[i][j])
                ans = f[i][j];
        }
    printf("%d", ans);
    return 0;
}