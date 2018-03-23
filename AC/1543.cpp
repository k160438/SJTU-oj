#include <iostream>
using namespace std;

bool mod3(long long k, long long n)
{
    int p, q;
    while (k > 0)
    {
        p = k % 3;
        q = n % 3;
        if (p > q)
            return true;
        k /= 3;
        n /= 3;
    }
    return false;
}

long long solve(long long n)
{
    long long ans = 0;
    int p, last = 0;
    while (n > 0)
    {
        p = n % 3;
        n /= 3;
        if (!p)
            ans += (2 + last) * n;
        else if (p == 1)
            ans += (1 + last) * n;
        last += last * (p + 1);
        // if (last > 1 && p > 1)
        //     last *= 2;
        // else
        //     last = p;
    }
    return ans;
}

int main()
{
    long long n, m = 1, ans = 0;
    int tmp;
    cin >> n;
    ans = n;
    while (n > 0)
    {
        tmp = n % 3;
        m *= (tmp + 1);
        n/=3;
    }
    cout<<ans+1-m;
    return 0;
}