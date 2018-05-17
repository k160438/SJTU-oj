#include <cstdio>
using namespace std;

int main()
{
    long *nums, *pq, largest;
    int n, k, head, tail;
    scanf("%d", &k);
    scanf("%d", &n);
    nums = new long[n + 5];
    pq = new long[n + 5];
    for (int i = 0; i < n; ++i)
        scanf("%d", &nums[i]);
    head = k;
    tail = k - 1;
    pq[--head] = nums[k - 1];
    largest = nums[k - 1];
    for (int i = k - 2; i >= 0; --i)
        if (nums[i] >= largest)
        {
            pq[--head] = nums[i];
            largest = nums[i];
        }

    printf("%ld ", pq[head]);
    for (int i = k; i < n; ++i)
    {
        if (nums[i - k] == pq[head])
            ++head;
        if (nums[i] > pq[head])
        {
            pq[head] = nums[i];
            tail = head;
        }
        else if (nums[i] == pq[head])
        {
            int m = head + 1;
            while (nums[i] == pq[m])
                ++m;
            pq[m] = nums[i];
            tail = m;
        }
        else if (nums[i] <= pq[tail])
            pq[++tail] = nums[i];
        else
        {
            int l = head, r = tail,mid;
            while(l<r-1)
            {
                mid = (l+r)>>1;
                if(pq[mid]<nums[i])
                r=mid;
                else
                l=mid;
            }
            pq[r] = nums[i];
            tail = r;
        }
        printf("%ld ", pq[head]);
    }

    return 0;
}