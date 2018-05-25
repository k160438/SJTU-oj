#include <iostream>
using namespace std;

struct Edge
{
    int start, end, weight;
};

class DisjointSet
{
    int *parent;

  public:
    DisjointSet(int n)
    {
        parent = new int[n + 1];
        for (int i = 1; i <= n; ++i)
            parent[i] = -1;
    }
    ~DisjointSet() { delete parent; }
    int find(int i);
    void Union(int a, int b);
};

int DisjointSet::find(int i)
{
    int ans = i, tmp;
    while (parent[ans] >= 0)
        ans = parent[ans];
    while (parent[i] >= 0)
    {
        tmp = parent[i];
        parent[i] = ans;
        i = tmp;
    }
    return ans;
}

void DisjointSet::Union(int a, int b)
{
    int x = find(a), y = find(b);
    if (parent[x] < parent[y])
    {
        parent[x] += parent[y];
        parent[y] = x;
    }
    else
    {
        parent[y] += parent[x];
        parent[x] = y;
    }
}

void quicksort(Edge A[], int l, int h)
{
    Edge k = A[l];
    int low = l, high = h;
    if (low >= high)
        return;
    while (low < high)
    {
        while (low < high && A[high].weight >= k.weight)
            --high;
        if (low < high)
            A[low++] = A[high];
        while (low < high && A[low].weight <= k.weight)
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
    int n, m, count = 0;
    long long ans = 0;
    Edge *A;
    cin >> n >> m;
    A = new Edge[m + 1];
    DisjointSet minTree(n);
    for (int i = 0; i < m; ++i)
        cin >> A[i].start >> A[i].end >> A[i].weight;
    quicksort(A, 0, m - 1);
    for (int i = 0; i < m; ++i)
        if (minTree.find(A[i].start) != minTree.find(A[i].end))
        {
            ++count;
            ans += A[i].weight;
            minTree.Union(A[i].start, A[i].end);
            if (count == n - 1)
                break;
        }
    cout << ans;
    delete A;
    return 0;
}