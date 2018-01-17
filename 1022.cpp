#include <iostream>
using namespace std;

//算法优化，拆成偶数对
int main()
{
    int n, a = 1, b = 1, tmp;
    cin >> n;
    if (n <= 2)
        cout << 1;
    else
    {
        if (n % 2 == 1)
        {
            b = 2;
        }
        n = n / 2 - 1;
        for (int i = 0; i < n; ++i)
        {
            a = (a + b)%2010;
            b = (a + b)%2010;
        }
        cout << b;
    }
}