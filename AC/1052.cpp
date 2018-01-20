#include <iostream>
using namespace std;

void setadd(bool *a, bool *b)
{
    for (int i = 0; i <= 200; ++i)
        if (b[i])
            a[i] = b[i];
}

void setminus(bool *a, bool *b)
{
    for (int i = 0; i <= 200; ++i)
        if (a[i] && b[i])
            a[i] = false;
}

void setmulti(bool *a, bool *b)
{
    for (int i = 0; i <= 200; ++i)
        if (a[i] && !b[i])
            a[i] = false;
}

int main()
{
    int N, M, setsize[101], i, j, tmp;
    bool **sets;
    char command;
    cin >> N;
    sets = new bool *[N];
    for (i = 0; i < N; ++i)
    {
        sets[i] = new bool[202];
        for (j = 0; j <= 200; ++j)
            sets[i][j] = false;
    }
    for (i = 0; i < N; ++i)
        cin >> setsize[i];
    for (i = 0; i < N; ++i)
        for (j = 0; j < setsize[i]; ++j)
        {
            cin >> tmp;
            sets[i][tmp] = true;
        }
    cin >> M;
    for (i = 0; i < M; ++i)
    {
        cin >> command >> j >> tmp;
        if (command == '+')
            setadd(sets[j - 1], sets[tmp - 1]);
        if (command == '-')
            setminus(sets[j - 1], sets[tmp - 1]);
        if (command == '*')
            setmulti(sets[j - 1], sets[tmp - 1]);
    }
    for (i = 0; i < N; ++i)
    {
        for (j = 0; j <= 200; ++j)
            if (sets[i][j])
                cout << j << ' ';
        cout << '\n';
    }
    return 0;
}