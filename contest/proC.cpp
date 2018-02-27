#include <cstdio>
using namespace std;
#define maxsize 2002

char classroom[maxsize][maxsize];

int main()
{
    int n, m, k, res = 0, lens = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
        scanf("%s", &classroom[i]);
    if (k <= m)
        for (int i = 0; i < n; ++i)
        {
            lens = 0;
            for (int j = 0; j < m; ++j)
                if (classroom[i][j] == '.')
                {
                    ++lens;
                    if (lens >= k)
                        ++res;
                }
                else
                    lens = 0;
        }
    if (k <= n)
        for (int i = 0; i < m; ++i)
        {
            lens = 0;
            for (int j = 0; j < n; ++j)
                if (classroom[j][i] == '.')
                {
                    ++lens;
                    if (lens >= k)
                        ++res;
                }
                else
                    lens = 0;
        }
    printf("%d", res);
    return 0;
}