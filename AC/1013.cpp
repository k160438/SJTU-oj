#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int V, N;
    int **f, c[1000], w[1000];
    cin >> V >> N;
    f = new int *[N + 1];
    for (int n = 0; n <= N; ++n)
        f[n] = new int[V + 1];
    for (int i = 0; i < N; ++i)
    {
        f[i][0] = 0;
        cin >> c[i] >> w[i];
    }
    f[N][0] = 0;
    for (int j = 0; j <= V; ++j)
        f[0][j] = 0;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= V; ++j)
        {
            if (j - c[i - 1] >= 0)
                f[i][j] = max(f[i - 1][j], f[i][j - c[i - 1]] + w[i - 1]);
            else
                f[i][j] = f[i - 1][j];
        }
    }
    cout << f[N][V];

    return 0;
}