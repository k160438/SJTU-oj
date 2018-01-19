#include <iostream>
using namespace std;

long long A(long long m, long long n)
{
    if (m == 0)
        return (n + 1);
    if (m == 1)
        return (n + 2);
    if (m == 2)
        return (2 * n + 3);
    if (n == 0)
        return A(m - 1, 1);
    return A(m - 1, A(m, n - 1));
}

int main()
{
    long long m, n;
    cin >> m >> n;
    cout << A(m, n);
    return 0;
}