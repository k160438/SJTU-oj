#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n, **f, count = 1;
    cin >> n;
    f = new int *[n];
    for (int i = 0; i < n; ++i)
        f[i] = new int[n];
    for (int i = 1; i <= n / 2; ++i)
    {
        for (int j = i - 1; j <= n - i; ++j)
            f[i - 1][j] = count++;
        for (int j = i; j < n - i; ++j)
            f[j][n - i] = count++;
        for (int j = n - i; j >= i - 1; --j)
            f[n - i][j] = count++;
        for (int j = n - i - 1; j > i - 1; --j)
            f[j][i - 1] = count++;
    }
    if (n % 2 > 0)
        f[n / 2][n / 2] = count++;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << setw(6) << f[i][j];
        cout << '\n';
    }
}