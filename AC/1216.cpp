#include <cstdio>
using namespace std;
#define maxsize 20005

class priority_q
{

  private:
    struct P
    {
        int id, num;
        bool operator<(const P &obj)
        {
            if (num == obj.num)
                return id < obj.id;
            return num < obj.num;
        }
        P() : id(0), num(2147483647) {}
    };
    P *heap;
    int heapsize;
    // void heapify(int i);
    void swap(P &a, P &b);
    P insideFind(const P &a, int x)
    {
        if (a.num > x)
            return a;
        if (a.id * 2 + 1 <= heapsize)
        {
            P left = insideFind(heap[a.id * 2], x);
            P right = insideFind(heap[a.id * 2 + 1], x);
            if (left < right)
                return left;
            return right;
        }
        if (a.id * 2 <= heapsize)
            return insideFind(heap[a.id * 2], x);
        return P();
    }

  public:
    priority_q() : heapsize(0)
    {
        heap = new P[maxsize];
    }
    ~priority_q() { delete heap; }
    void insert(int x);
    int find(int x);
    void decrease(int i, int v);
};

void priority_q::swap(P &a, P &b)
{
    int tmp = a.num;
    a.num = b.num;
    b.num = tmp;
    // tmp = a.id;
    // a.id = b.id;
    // b.id = tmp;
}

// void priority_q::heapify(int i)
// {
//     int smallest = i;
//     if (2 * i <= heapsize && heap[2 * i] < heap[smallest])
//         smallest = 2 * i;
//     if (2 * i + 1 <= heapsize && heap[2 * i + 1] < heap[smallest])
//         smallest = 2 * i + 1;
//     if (smallest != i)
//     {
//         swap(heap[i], heap[smallest]);
//         heapify(smallest);
//     }
// }

void priority_q::decrease(int i, int v)
{
    heap[i].num = heap[i].num - v;
    while (i > 1 && heap[i] < heap[i >> 1])
    {
        swap(heap[i], heap[i >> 1]);
        i >>= 1;
    }
}

void priority_q::insert(int x)
{
    heap[++heapsize].num = x;
    heap[heapsize].id = heapsize;
    int i = heapsize;
    while (i > 1 && heap[i] < heap[i >> 1])
    {
        swap(heap[i], heap[i >> 1]);
        i >>= 1;
    }
}

int priority_q::find(int x)
{
    return insideFind(heap[1], x).id;
}

int main()
{
    int m, v, j;
    char command[10];
    priority_q minHeap;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%s", command);
        if (command[0] == 'd')
        {
            scanf("%d %d", &j, &v);
            minHeap.decrease(j, v);
        }
        else
        {
            scanf("%d", &j);
            if(command[0]=='i')
            minHeap.insert(j);
            else
            printf("%d\n", minHeap.find(j));
        }
    }
    return 0;
}