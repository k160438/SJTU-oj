#include <iostream>
using namespace std;

int d[200005];
long long times[200005], count[100000] = {0};

int main()
{
    int S, T;
    cin >> S >> T;
    int i, j, tmp, res = 1;
    count[1] = T - S + 1;
    for (i = S; i <= T; ++i)
    {
        d[i] = 1;
        times[i] = 1;
    }
    for (i = S; i <= T; ++i)
    {
        for (j = 1; j <= 100; ++j)
            if (((i * j) % 100 == 0) && (i * j / 100 <= T - i))
            {
                tmp = i * j / 100 + i;
                if (d[tmp] == d[i] + 1)
                    times[tmp] += times[i];
                if (d[tmp] < d[i] + 1)
                {
                    d[tmp] = d[i] + 1;
                    times[tmp] = times[i];
                }
                res = res < d[tmp] ? d[tmp] : res;
                count[d[i] + 1] += times[i]; //not repeat
            }
    }
    cout << res << '\n'
         << count[res];
}