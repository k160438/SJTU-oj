#include <iostream>
using namespace std;
#define maxsize 1000

int A[maxsize];
int heapsize;

void MAXHEAPIFY(int A[], int i)
{
    int tmp, largest = i;
    if (2 * i <= heapsize && A[2 * i - 1] > A[largest - 1])
        largest = 2 * i;
    if (2 * i + 1 <= heapsize && A[2 * i] > A[largest - 1])
        largest = 2 * i + 1;
    if (largest != i)
    {
        tmp = A[largest - 1];
        A[largest - 1] = A[i - 1];
        A[i - 1] = tmp;
        MAXHEAPIFY(A, largest);
    }
}

void BUILDHEAP(int A[])
{
    if (heapsize <= 1)
        return;
    int tmp = 1, i = 1;
    while (i < heapsize)
    {
        tmp *= 2;
        i += tmp;
    }
    for (i = i - tmp; i >= 1; --i)
        MAXHEAPIFY(A, i);
}

int heapMaximum(int A[])
{
    return A[0];
}

int heapExtractMax(int A[])
{
    if (heapsize < 1)
    {
        cout << "heap underflow" << endl;
        return 0;
    }
    int res = A[0];
    A[0] = A[--heapsize];
    MAXHEAPIFY(A, 1);
    return res;
}

void heapIncreaseKey(int A[], int i, int k)
{
    if (k < A[i - 1])
    {
        cout << "new key is less than current key!" << endl;
    }
    else
    {
        int tmp;
        A[i - 1] = k;
        while (i > 1)
        {
            if (A[i / 2 - 1] < A[i - 1])
            {
                tmp = A[i - 1];
                A[i - 1] = A[i / 2 - 1];
                A[i / 2 - 1] = tmp;
                i /= 2;
            }
            else
                break;
        }
    }
}

void heapInsert(int A[], int key)
{
    ++heapsize;
    A[heapsize - 1] = -10000000;
    heapIncreaseKey(A, heapsize, key);
}

void print(int A[])
{
    for (int i = 0; i < heapsize; ++i)
        cout << A[i] << ' ';
    cout << endl;
}

int main()
{
    heapsize = 10;
    for (int i = 0; i < 10; ++i)
        A[i] = 10 - i;

    BUILDHEAP(A);
    print(A);
    cout << heapMaximum(A) << endl;
    cout << heapExtractMax(A) << endl;
    cout << heapExtractMax(A) << endl;
    print(A);
    heapInsert(A, 13);
    heapInsert(A, 15);
    print(A);
    cout << heapExtractMax(A) << endl;
    cout << heapExtractMax(A) << endl;
    cout << heapExtractMax(A) << endl;
    cout << heapExtractMax(A) << endl;
    print(A);
    return 0;
}