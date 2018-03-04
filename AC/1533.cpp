#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, x, y, res = -1;
    float k;
    cin >> n >> y >> x;
    k = n + 1;
    m=n;
    k /= 2;
    k = k - max(abs(k - x), abs(k - y));
    for (int i = 1; i < k; ++i)
    {
        res += 4 * (m - 1);
        m -= 2;
    }
    if (y == k)
        res += 1 + x - k;
    else if (x == n - k + 1)
        res += n + 2 - 3 * k + y;
    else if (y == n - k + 1)
        res += 3 * n - x + 4 - 5 * k;
    else
        res += 4 * (m - 1) - y + k + 1;
    cout << res;
    return 0;
}