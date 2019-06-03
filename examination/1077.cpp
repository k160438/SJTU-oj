#include <iostream>
#include <algorithm>
using namespace std;
#define maxsize 35

int OPT[maxsize][maxsize] = {0};
int score[maxsize];
int n;

// index count from 1

void DLR(int start, int end)
{
    if (start == end)
    {
        cout << start << ' ';
        return;
    }
    if (OPT[start][end] == OPT[start][start] + OPT[start + 1][end])
    {
        cout << start << ' ';
        DLR(start + 1, end);
        return;
    }
    if (OPT[start][end] == OPT[end][end] + OPT[start][end - 1])
    {
        cout << end << ' ';
        DLR(start, end - 1);
        return;
    }
    for (int i = start + 1; i <= end - 1; ++i)
        if (OPT[start][end] == OPT[start][i - 1] * OPT[i + 1][end] + OPT[i][i])
        {
            cout << i << ' ';
            DLR(start, i - 1);
            DLR(i + 1, end);
        }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> score[i];
    for (int i = 1; i <= n; ++i)
        OPT[i][i] = score[i];
    for (int i = 1; i < n; ++i)
        OPT[i][i + 1] = OPT[i][i] + OPT[i + 1][i + 1];
    for (int i = 2; i <= n - 1; ++i)
        for (int j = 1; j <= n - i; ++j)
        {
            OPT[j][j + i] = max(OPT[j][j] + OPT[j + 1][j + i], OPT[j + i][j + i] + OPT[j][j + i - 1]);
            for (int k = j + 1; k < j + i; ++k)
                OPT[j][j + i] = max(OPT[j][j + i], OPT[k][k] + OPT[j][k - 1] * OPT[k + 1][j + i]);
        }
    cout << OPT[1][n] << endl;
    DLR(1, n);
    return 0;
}