#include <cstdio>
#include <stack>
using namespace std;
#define MAX_INT 2147483647

struct Node
{
    int dis, id;
};

template <class T>
class priorityQueue
{
  private:
    int currentSize;
    T *array;
    int maxSize;

    void doubleSpace();
    void buildHeap();
    void minHeapify(int root);

  public:
    priorityQueue(int capacity = 100) : maxSize(capacity), currentSize(0)
    {
        array = new T[capacity];
    }
    ~priorityQueue() { delete[] array; }
    bool isEmpty() { return currentSize == 0; }
    void enQueue(int d, int num);
    T deQueue()
    {
        T ans = array[0];
        array[0] = array[--currentSize];
        minHeapify(1);
        return ans;
    }
    T getHead() { return array[0]; }
};

template <class T>
void priorityQueue<T>::doubleSpace()
{
    T *tmp = array;
    array = new T[maxSize << 1];
    for (int i = 0; i < currentSize; ++i)
        array[i] = tmp[i];
    maxSize <<= 1;
    delete[] tmp;
}

template <class T>
void priorityQueue<T>::minHeapify(int root)
{
    int Min;
    T tmp;
    for (; root << 1 <= currentSize; root = Min)
    {
        Min = root << 1;
        if (Min < currentSize && array[Min - 1].dis > array[Min].dis)
            ++Min;
        if (array[Min - 1].dis < array[root - 1].dis)
        {
            tmp = array[Min - 1];
            array[Min - 1] = array[root - 1];
            array[root - 1] = tmp;
        }
        else
            break;
    }
}

template <class T>
void priorityQueue<T>::buildHeap()
{
    if (currentSize <= 1)
        return;
    int tmp = 1;
    while (tmp < currentSize + 1)
        tmp <<= 1;
    for (int i = (tmp >> 1) - 1; i > 0; --i)
        minHeapify(i);
}

template <class T>
void priorityQueue<T>::enQueue(int d, int num)
{
    int i;
    T tmp;
    ++currentSize;
    if (currentSize > maxSize)
        doubleSpace();
    array[currentSize - 1].id = num;
    array[currentSize - 1].dis = d;
    i = currentSize;
    while (i > 1)
    {
        if (array[(i >> 1) - 1].dis > array[i - 1].dis)
        {
            tmp = array[(i >> 1) - 1];
            array[(i >> 1) - 1] = array[i - 1];
            array[i - 1] = tmp;
        }
        i >>= 1;
    }
}

class Dijkstra
{
    struct edgeNode
    {
        int end, weight;
        edgeNode *next;
        edgeNode(int e, int w, edgeNode *n) : end(e), weight(w), next(n) {}
    };
    struct verNode
    {
        int id, dis, prev, step;
        edgeNode *head;
        verNode(edgeNode *n = NULL) : head(n), dis(MAX_INT), step(MAX_INT), prev(0) {}
    };
    int size, edge;
    bool *covered;
    verNode *verList;

  public:
    Dijkstra(int n) : size(n), edge(0)
    {
        verList = new verNode[n + 1];
        covered = new bool[n + 1];
        for (int i = 1; i <= n; ++i)
        {
            covered[i] = false;
            verList[i].id = i;
        }
    }
    ~Dijkstra()
    {
        edgeNode *p, *q;
        for (int i = 1; i <= size; ++i)
        {
            p = verList[i].head;
            while (p)
            {
                q = p;
                p = p->next;
                delete q;
            }
        }
        delete verList;
    }

    bool insert(int a, int b, int w);
    int edg() { return edge; }
    void findShortest(int start, int end);
};

bool Dijkstra::insert(int a, int b, int w)
{
    Dijkstra::edgeNode *p = verList[a].head;
    while (p)
    {
        if (p->end == b)
            return false;
        p = p->next;
    }
    verList[a].head = new edgeNode(b, w, verList[a].head);
    ++edge;
    return true;
}

void Dijkstra::findShortest(int start, int end)
{
    int source = start;
    edgeNode *tmp;
    priorityQueue<Node> q;
    covered[start] = true;
    verList[start].dis = 0;
    verList[start].step = 0;
    while (source != end)
    {
        tmp = verList[source].head;
        while (tmp)
        {
            if (verList[tmp->end].dis > verList[source].dis + tmp->weight)
            {
                verList[tmp->end].dis = verList[source].dis + tmp->weight;
                verList[tmp->end].step = verList[source].step + 1;
                verList[tmp->end].prev = source;
                q.enQueue(verList[tmp->end].dis, tmp->end);
            }
            else if (verList[tmp->end].dis == verList[source].dis + tmp->weight && verList[tmp->end].step > verList[source].step + 1)
            {
                verList[tmp->end].step = verList[source].step + 1;
                verList[tmp->end].prev = source;
            }
            tmp = tmp->next;
        }
        while (covered[source])
            source = (q.deQueue()).id;
        covered[source] = true;
        if (source == end)
            break;
    }
    printf("%d\n", verList[end].dis);
    stack<int> path;
    int p = end;
    path.push(p);
    while (verList[p].prev)
    {
        p = verList[p].prev;
        path.push(p);
    }
    while(path.size())
    {
        p = path.top();
        path.pop();
        printf("%d ", p);
    }
}

int main()
{
    int n, m, start, end, a, b, w;
    scanf("%d %d %d %d", &n, &m, &start, &end);
    Dijkstra graph(n);
    for(int i=0;i<m;++i)
    {
        scanf("%d %d %d", &a, &b, &w);
        graph.insert(a, b, w);
    }    
    // printf("%s", "start!\n");
    graph.findShortest(start, end);
    return 0;
}