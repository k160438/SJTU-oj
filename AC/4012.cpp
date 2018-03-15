#include <cstdio>
#include <algorithm>
using namespace std;
#define maxsize 10005

int heap[maxsize], res = 0, heapsize = 0;

void swap(int &a, int &b)
{
    int tmp = b;
    b = a;
    a = tmp;
}

void insert(int x)
{
    int i = heapsize + 1;
    heap[++heapsize] = x;
    while (i > 1)
    {
        if (heap[i] < heap[i >> 1])
            swap(heap[i], heap[i >> 1]);
        else
            break;
        i >>= 1;
    }
}

void heapify(int i)
{
    int smallest = i;
    if (2 * i <= heapsize && heap[2 * i] < heap[smallest])
        smallest = 2 * i;
    if (2 * i + 1 <= heapsize && heap[2 * i + 1] < heap[smallest])
        smallest = 2 * i + 1;
    if (smallest != i)
    {
        swap(heap[i], heap[smallest]);
        heapify(smallest);
    }
}

void oneMerge()
{
    if (heapsize < 3)
    {
        res += heap[1] + heap[2];
        return;
    }
    int i;
    if (heap[2] > heap[3])
        i = 3;
    else
        i = 2;
    res += heap[1] + heap[i];
    heap[1] += heap[i];
    heap[i] = heap[heapsize--];
    heapify(i);
    heapify(1);
}

int main()
{
    int n, tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        insert(tmp);
    }
    for (int i = 1; i < n; ++i)
        oneMerge();
    printf("%d", res);
    return 0;
}