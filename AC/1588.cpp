#include <cstdio>
using namespace std;
#define maxsize 1000005

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
    void heapify(int i);
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
    int getLength(){return heapsize;}
};

void priority_q::swap(P &a, P &b)
{
    int tmp = a.num;
    a.num = b.num;
    b.num = tmp;
}

void priority_q::heapify(int i)
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
    int i;
    if(!heapsize || (i=insideFind(heap[1], x).id)==0)
    {
        insert(x);
    }
    else
    {
        heap[i].num = x;
        while (i > 1 && heap[i] < heap[i >> 1])
        {
            swap(heap[i], heap[i >> 1]);
            i >>= 1;
        }
    }
}

int len = 1;

int binaryfind(int *mintail, int x)
{
    int mid, l = 1, r = len;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (mintail[mid] >= x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}


int main()
{
    int n,k;
    int *nums, *mintail;
    priority_q minHeap;
    scanf("%d", &n);
    nums = new int[n + 5];
    mintail = new int[n + 5];
    for(int i=0;i<n;++i)
    {
        scanf("%d", &nums[i]);
        minHeap.find(nums[i]);
    }
    mintail[1] = nums[0];
    for (int i = 1; i < n; ++i)
    {
        k = binaryfind(mintail, nums[i]);
        mintail[k] = nums[i];
        if(k>len) len=k;
    }
    printf("%d\n", len);
    printf("%d", minHeap.getLength());
    return 0;
}
