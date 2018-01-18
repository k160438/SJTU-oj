#include <iostream>
using namespace std;

//算法优化，拆成偶数对
// int main()
// {
//     int n, a = 1, b = 1, tmp;
//     cin >> n;
//     if (n <= 2)
//         cout << 1;
//     else
//     {
//         if (n % 2 == 1)
//         {
//             b = 2;
//         }
//         n = n / 2 - 1;
//         for (int i = 0; i < n; ++i)
//         {
//             a = (a + b)%2010;
//             b = (a + b)%2010;
//         }
//         cout << b;
//     }
// }

//矩阵快速幂
void multi(int a[2][2], int b[2][2])
{
    int tmp[2][2] = {{0}};
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                tmp[i][j] += (a[i][k] * b[k][j]);
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            a[i][j] = tmp[i][j] % 2010;
}

int main()
{
    int a[2][2] = {{1, 1}, {1, 0}};
    int res[2][2] = {{1, 0}, {0, 1}};
    long long n;
    cin >> n;
    if (n <= 2)
    {
        if (n == 0)
            cout << 0;
        else
        cout << 1;
    }
    else
    {
        n -= 2;
        while (n > 0)
        {
            if (n & 1)
                multi(res, a);
            n >>= 1;
            multi(a, a);
        }
        cout << (res[0][0] + res[0][1]) % 2010;
    }

    return 0;
}