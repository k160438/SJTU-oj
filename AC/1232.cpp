#include <iostream>
#include <stack>
using namespace std;

class DisjointSet
{
    struct Node
    {
        int p;
        int adjacent[4];
    };
    Node *parent;
    int size;
    int *covered, *path;

  public:
    DisjointSet(int n) : size(n)
    {
        parent = new Node[n + 1];
        covered = new int[n + 1];
        path = new int[n + 1];
        for (int i = 0; i <= n; ++i)
        {
            parent[i].p = -1;
            for (int j = 0; j < 4; ++j)
                parent[i].adjacent[j] = 0;
        }
    }
    ~DisjointSet() { delete[] parent; }
    void Union(int a, int b);
    int Find(int a);
    void link(int a, int b, int q);
    void searchPath(int A, int B);
};

void DisjointSet::Union(int a, int b)
{
    int x = Find(a), y = Find(b);
    if (x == y)
        return;
    if (parent[x].p < parent[y].p)
    {
        parent[x].p += parent[y].p;
        parent[y].p = x;
    }
    else
    {
        parent[y].p += parent[x].p;
        parent[x].p = y;
    }
}

int DisjointSet::Find(int a)
{
    int ans = a, next = a, tmp;
    while (parent[ans].p > 0)
        ans = parent[ans].p;
    while (parent[next].p > 0 && parent[next].p != ans)
    {
        tmp = parent[next].p;
        parent[next].p = ans;
        next = tmp;
    }
    return ans;
}

void DisjointSet::link(int a, int b, int q)
{
    parent[a].adjacent[q] = b;
    parent[b].adjacent[3 - q] = a;
}

void DisjointSet::searchPath(int A, int B)
{
    int pos,t;
    stack<int> s, ans;
    for (int i = 0; i <= size; ++i)
    {
        path[i] = 0;
        covered[i] = 1;
    }
    s.push(A);
    while(s.size())
    {
        pos = s.top();
        s.pop();
        if(pos==B) break;
        covered[pos] = 0;
        for(int i=3;i>=0;--i)
        {
            t = parent[pos].adjacent[i];
            if(t>0 && covered[t])
            {
                s.push(t);
                path[t] = pos;
            }
        }
    }
    t = B;
    while(t!=A)
    {
        ans.push(t);
        t = path[t];
    }
    ans.push(A);
    while(ans.size())
    {
        cout<<ans.top()<<' ';
        ans.pop();
    }
}

int main()
{
    int N, A, B, p, q, i, tmp;
    cin >> N >> A >> B;
    DisjointSet maze(N * (N + 1) / 2);
    while(cin>>p>>q)
    {
        tmp = 0;
        i = 0;
        while (tmp < p)
            tmp += ++i;
        switch (q)
        {
        case 0:
            if (p + i - tmp > 1)
            {
                maze.Union(p, p - i);
                maze.link(p, p - i, q);
            }
            break;
        case 1:
            if (p != tmp)
            {
                maze.Union(p, p - i + 1);
                maze.link(p, p - i + 1, q);
            }
            break;
        case 2:
            maze.Union(p, p + i);
            maze.link(p, p + i, q);
            break;
        default:
            maze.Union(p, p + i + 1);
            maze.link(p, p + i + 1, q);
        }

        if (maze.Find(A) == maze.Find(B))
            break;
    }
    maze.searchPath(A, B);
    return 0;
}