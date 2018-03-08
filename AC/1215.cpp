#include <cstdio>
using namespace std;
#define maxsize 20005

int minheap[maxsize];
int heapsize = 0;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void heapify(int i)
{
    int smallest = i, tmp;
    if (2 * i <= heapsize && minheap[2 * i] < minheap[smallest])
        smallest = 2 * i;
    if (2 * i + 1 <= heapsize && minheap[2 * i + 1] < minheap[smallest])
        smallest = 2 * i + 1;
    if (smallest != i)
    {
        swap(minheap[smallest], minheap[i]);
        heapify(smallest);
    }
}

void insert(int k)
{
    int i = ++heapsize;
    minheap[heapsize] = k;
    while (i > 1)
    {
        if (minheap[i] < minheap[i >> 1])
        {
            swap(minheap[i], minheap[i >> 1]);
            i >>= 1;
        }
        else
            break;
    }
}

void opDelete()
{
    minheap[1] = minheap[heapsize--];
    heapify(1);
}

int main()
{
    int M, k;
    char command[10];
    scanf("%d", &M);
    for (int i = 0; i < M; ++i)
    {
        scanf("%s", command);
        switch (command[0])
        {
        case 'i':
            scanf("%d", &k);
            insert(k);
            break;
        case 'd':
            opDelete();
            break;
        default:
            printf("%d\n", minheap[1]);
        }
    }
    return 0;
}