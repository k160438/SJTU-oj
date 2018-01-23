#include <cstdio>
#include <algorithm>
using namespace std;
#define maxsize 1003

char a[maxsize] = {0}, b[maxsize] = {0};
int trial[maxsize][maxsize];

int main()
{
    int n, m;
    scanf("%s", &a);
    scanf("%s", &b);
    for (int i = maxsize - 1; i >= 0; --i)
        if (a[i])
        {
            m = i + 1;
            break;
        }
    for (int i = maxsize - 1; i >= 0; --i)
        if (b[i])
        {
            n = i + 1;
            break;
        }

    for (int i = 0; i < m; ++i)
        trial[i][0] = 0;
    for (int i = 0; i < n; ++i)
        trial[0][i] = 0;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (a[i - 1] == b[j - 1])
                trial[i][j] = trial[i - 1][j - 1] + 1;
            else
                trial[i][j] = max(trial[i - 1][j], trial[i][j - 1]);
        }
    printf("%d", trial[m][n]);
    return 0;
}