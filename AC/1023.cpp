#include <iostream>
using namespace std;

void transform(int **f, int length, int b)
{
    int tmp;
    if (b == 0)
    {
        for (int i = 1; i <= length / 2; ++i)
            for (int j = 0; j < length; ++j)
            {
                tmp = f[j][i - 1];
                f[j][i - 1] = f[j][length - i];
                f[j][length - i] = tmp;
            }
    }
    if (b == 1)
    {
        for (int i = 1; i <= length / 2; ++i)
            for (int j = 0; j < length; ++j)
            {
                tmp = f[i - 1][j];
                f[i - 1][j] = f[length - i][j];
                f[length - i][j] = tmp;
            }
    }
    if (b == 2)
    {
        for (int i = 0; i < length; ++i)
            for (int j = 0; j < i; ++j)
            {
                tmp = f[i][j];
                f[i][j] = f[j][i];
                f[j][i] = tmp;
            }
    }
}

int main()
{
    int n, b, *length, ***f;
    cin >> n;
    if (n > 0)
    {
        f = new int **[n];
        length = new int[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> length[i] >> b;
            f[i] = new int *[length[i]];
            for (int j = 0; j < length[i]; ++j)
            {
                f[i][j] = new int[length[i]];
                for (int k = 0; k < length[i]; ++k)
                    cin >> f[i][j][k];
            }
            transform(f[i], length[i], b);
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < length[i]; ++j)
            {
                for (int k = 0; k < length[i]; ++k)
                    cout << f[i][j][k] << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}