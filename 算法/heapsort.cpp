#include <iostream>
using namespace std;
#define maxsize 1000

int A[maxsize], length, heapsize;

void MAX_HEAPIFY(int A[], int i)
{
    int tmp, largest = i;
    if (2 * i <= heapsize && A[2 * i - 1] > A[largest - 1])
        largest = 2 * i;
    if (2 * i + 1 <= heapsize && A[2 * i] > A[largest - 1])
        largest = 2 * i + 1;
    if (largest != i)
    {
        tmp = A[i - 1];
        A[i - 1] = A[largest - 1];
        A[largest - 1] = tmp;
        MAX_HEAPIFY(A, largest);
    }
}

void heapsort(int A[])
{
    if (length == 1)
        return;
    int tmp = 1, i = 1;
    while (i < length)
    {
        tmp *= 2;
        i += tmp;
    }
    for (i = i - tmp; i >= 1; --i)
        MAX_HEAPIFY(A, i);
    for (i = length; i > 2; --i)
    {
        tmp = A[heapsize - 1];
        A[heapsize - 1] = A[0];
        A[0] = tmp;
        --heapsize;
        MAX_HEAPIFY(A, 1);
    }
    tmp = A[1];
    A[1] = A[0];
    A[0] = tmp;
}

int main()
{
    cin >> length;
    heapsize = length;
    for (int i = 0; i < length; ++i)
        cin >> A[i];
    heapsort(A);
    for (int i = 0; i < length; ++i)
        cout << A[i] << ' ';
    cout << endl;
    return 0;
}