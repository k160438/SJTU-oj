#include <iostream>
using namespace std;
#define maxsize 100005

int nums[maxsize];

int main()
{
    int N, T, a, l, r, mid;
    ios::sync_with_stdio(false);
    cin >> N >> T;
    for (int i = 1; i <= N; ++i)
        cin >> nums[i];
    for (int i = 0; i < T; ++i)
    {
        cin >> a;
        if (nums[1] > a)
        {
            cout << N << '\n';
            continue;
        }
        if (nums[N] <= a)
        {
            cout << 0 << '\n';
            continue;
        }
        l = 1;
        r = N;

        while (l < r - 1)
        {
            mid = (l + r) >> 1;
            if (nums[mid] > a)
                r = mid;
            else
                l = mid;
        }
        if (nums[r] > a && nums[l] <= a)
            cout << N + 1 - r << '\n';
    }

    return 0;
}
