#include <iostream>
using namespace std;
 
void quicksort(int *A, int l, int h)
{
    int k, m, low = l, high = h, mid = (l + h) >> 1;
    if (low >= high)
        return;
    if (A[l] > A[mid])
    {
        if (A[l] < A[h])
        {
            k = A[l];
            m = l;
        }
        else
        {
            k = A[mid] > A[h] ? A[mid] : A[h];
            m = A[mid] > A[h] ? mid : h;
        }
    }
    else
    {
        if (A[l] > A[h])
        {
            k = A[l];
            m = l;
        }
        else
        {
            k = A[mid] < A[h] ? A[mid] : A[h];
            m = A[mid] < A[h] ? mid : h;
        }
    }
 
    if (low != m)
    {
        A[m] = A[low];
        A[low] = k;
    }
 
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
    int *A, n;
    cin >> n;
    A = new int[n+5];
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    quicksort(A, 0, n - 1);
    for (int i = 0; i < n; ++i)
        cout << A[i] << ' ';
    delete A;
    return 0;
}