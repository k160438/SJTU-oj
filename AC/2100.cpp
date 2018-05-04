#include <cstdio>
using namespace std;

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
    priorityQueue(const T data[], int size);
    ~priorityQueue() { delete[] array; }
    bool isEmpty() { return currentSize == 0; }
    void enQueue(const T &x);
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
priorityQueue<T>::priorityQueue(const T data[], int size)
{
    maxSize = size + 5;
    array = new T[maxSize];
    currentSize = size;
    for (int i = 0; i < currentSize; ++i)
        array[i] = data[i];
    buildHeap();
}

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
        if (Min < currentSize && array[Min - 1] > array[Min])
            ++Min;
        if (array[Min - 1] < array[root - 1])
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
void priorityQueue<T>::enQueue(const T &x)
{
    int i;
    T tmp;
    ++currentSize;
    if (currentSize > maxSize)
        doubleSpace();
    array[currentSize - 1] = x;
    i = currentSize;
    while (i > 1)
    {
        if (array[(i >> 1) - 1] > array[i - 1])
        {
            tmp = array[(i >> 1) - 1];
            array[(i >> 1) - 1] = array[i - 1];
            array[i - 1] = tmp;
        }
        i >>= 1;
    }
}


int main()
{
    int n, newnode, tmp;
    long long ans = 0;
    priorityQueue<int> q(2000);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        q.enQueue(tmp);
    }

    while (n > 1)
    {
        newnode = 0;
        for (int i = 0; i < 2; ++i)
        {
            newnode += q.deQueue();
        }
        ans += newnode;
        q.enQueue(newnode);
        n -= 1;
    }

    printf("%lld", ans);
    return 0;
}