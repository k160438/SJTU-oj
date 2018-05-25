#include <iostream>
using namespace std;

void quicksort(int A[], int l, int h)
{
    int k = A[l], low = l, high = h;
    if (low >= high)
        return;
    while (low < high)
    {
        while (low < high && A[high] >= k)
            --high;
        if (low < high)
            A[low++] = A[high];
        while (low < high && A[low] <= k)
            ++low;
        if (low < high)
            A[high--] = A[low];
    }
    A[low] = k;
    quicksort(A, l, low - 1);
    quicksort(A, low + 1, h);
}

int main()
{
    int A[1000], n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    quicksort(A, 0, n - 1);
    for (int i = 0; i < n; ++i)
        cout << A[i] << ' ';
    return 0;
}