#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, M, count, high[10002], low[10002], i, j;
    cin >> N >> M;
    count = N;
    for (i = 0; i < N; ++i)
        cin >> high[i];
    for (i = 0; i < M; ++i)
        cin >> low[i];
    sort(high, high + N);
    sort(low, low + M);
    j = M - 1;
    for (i = N - 1; i >= 0; --i)
    {
        while (j >= 0 && high[i] <= low[j])
            --j;
        if (j >= 0)
        {
            --j;
            ++count;
        }
        else
            break;
    }
    cout << count;
    return 0;
}