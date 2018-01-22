#include <iostream>
#include <algorithm>
using namespace std;

long long res[2];
long long customers[100000];
long long wait[3] = {0};

void tradition(int N)
{
    int i, j;
    long long W = 0, T = 0, w, t;
    for (i = 0; i < 3; ++i)
    {
        w = 0;
        t = 0;
        for (j = i; j < N; j += 3)
        {
            W += w;
            w += customers[j];
            t += customers[j];
        }
        T = max(T, t);
    }
    res[0] = W;
    res[1] = T;
}

int getMinIndex()
{
    int res = 0;
    if (wait[1] < wait[res])
        res = 1;
    if (wait[2] < wait[res])
        res = 2;
    return res;
}

void modern(int N)
{
    long long W = 0, T = 1;
    int i, j;
    long long tmp = 0;
    for (i = 0; i < N; ++i)
    {
        j = getMinIndex();
        W += wait[j];
        wait[j] += customers[i];
    }
    T = max(wait[0], max(wait[1], wait[2]));
    res[0] = W;
    res[1] = T;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> customers[i];
    tradition(N);
    cout << res[0] << ' ' << res[1] << '\n';
    modern(N);
    cout << res[0] << ' ' << res[1];
}