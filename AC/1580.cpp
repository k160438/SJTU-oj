#include <cstdio>
using namespace std;

int len = 1;

int find(int *mintail, int x)
{
    int mid, l = 1, r = len;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (mintail[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

int main()
{
    int *nums, *mintail;
    int n, k;
    scanf("%d", &n);
    nums = new int[n + 5];
    mintail = new int[n + 5];
    for (int i = 0; i < n; ++i)
        scanf("%d", &nums[i]);
    mintail[1] = nums[0];
    for (int i = 1; i < n; ++i)
    {
        k = find(mintail, nums[i]);
        mintail[k] = nums[i];
        if(k>len) len=k;
    }
    printf("%d", len);
    return 0;
}