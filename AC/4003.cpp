#include <iostream>
#include <math.h>
using namespace std;
#define maxsize 30

int solve(int n, int k)
{
    if (n <= k)
        return k - n;
    int i = 0, count = 0, res, bin[maxsize] = {0};
    while (n > 0)
    {
        if (n & 1)
        {
            bin[i] = 1;
            ++count;
        }
        ++i;
        n >>= 1;
    }
    if (count <= k)
        return 0;
    while (k > 0)
        if (bin[--i])
            --k;
    res = pow(2, i);
    for (int j = i - 1; j >= 0; --j)
        if (bin[j])
            res -= pow(2, j);
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << solve(n, k);
    return 0;
}
