#include <iostream>
using namespace std;
#define maxN 100010
#define maxK 13

long long nums[maxN][maxK] = {{0}};
long long a[maxN];

int main()
{
    int i, j, m, n, k;
    long long count;
    cin >> n >> k;
    for (i = 0; i < n; ++i)
        cin >> a[i];
    nums[0][2] = 0;
    for (i = 1; i < n; ++i)
    {
        count = 0;
        for (j = 0; j < i; ++j)
            if (a[j] > a[i])
                count++;
        nums[i][2] = count;
    }
    for (i = 3; i <= k; ++i)
        for (j = 0; j < n; ++j)
        {
            for (m = 0; m < j; ++m)
                if (a[m] > a[j])
                    nums[j][i] += nums[m][i - 1];
            nums[j][i] %= 1000000007;
        }
    count = 0;
    for (i = 0; i < n; ++i)
        count += nums[i][k];
    cout << count % 1000000007;

    return 0;
}