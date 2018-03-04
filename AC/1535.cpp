#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int range[2];

void rangeOfnumsum(long long l, long long r)
{
    int m = 0, n = 0, a, k = 0, t = 0, x = 0;
    int p[15], q[15];
    while (r > 0)
    {
        q[n++] = r % 10;
        k += q[n - 1];
        r /= 10;
    }
    while (l > 0)
    {
        p[m++] = l % 10;
        l /= 10;
    }
    if (m == n)
    {
        while (m > 0 && p[m - 1] == q[m - 1])
        {
            x += p[m - 1];
            --m;
        }
        k = 0;
        a = m;
        while (m > 0)
        {
            t += p[--m];
            k += q[m];
        }
        if (a == 0)
        {
            range[0] = x;
            range[1] = x;
        }
        else
        {
            range[0] = x + min(t, p[a - 1] + 1);
            range[1] = x + max(k, q[a - 1] + 9 * a - 10);
        }
    }
    else
    {
        range[1] = max(k, q[n - 1] + 9 * n - 10);
        range[0] = 1;
    }
}

int numsum(long long x)
{
    int res = 0;
    while (x > 0)
    {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    int res[100], n = 0;
    long long tmp, l, r;
    long long k, p, q;
    cin >> k >> p >> q;
    cin >> l >> r;
    rangeOfnumsum(l, r);
    for (int i = range[0]; i <= range[1]; ++i)
    {
        tmp = pow(i, k) * p + q;
        if (tmp<=r && tmp>=l && i==numsum(tmp))
            res[n++] = tmp;
    }
    cout << n << '\n';
    if (n > 0)
    {
        sort(res, res + n);
        for (int i = 0; i < n; ++i)
            cout << res[i] << ' ';
    }
    else
        cout << -1;
    return 0;
}