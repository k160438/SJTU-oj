#include <iostream>
using namespace std;
#define maxsize 100006

int heights[maxsize], tmp[maxsize];
long long c = 0;

void merge(int l, int mid, int r)
{
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (heights[i] > heights[j])
        {
            c += mid - i + 1;
            tmp[k++] = heights[j++];
        }
        else
            tmp[k++] = heights[i++];
    }
    while (i <= mid)
        tmp[k++] = heights[i++];
    while (j <= r)
        tmp[k++] = heights[j++];
    for (i = l; i <= r; ++i)
        heights[i] = tmp[i];
}

void mysort(int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) >> 1;
        mysort(l, mid);
        mysort(mid + 1, r);
        merge(l, mid, r);
    }
}

int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> heights[i];
    mysort(0, n - 1);
    cout << c;
    return 0;
}