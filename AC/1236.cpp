#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

class Graph
{
    struct EdgeNode
    {
        int weight, end;
        EdgeNode *next;
        EdgeNode(int e, int w, EdgeNode *n) : weight(w), end(e), next(n) {}
    };

    EdgeNode **verList;
    int edge, vertice;

  public:
    Graph(int n) : vertice(n), edge(0)
    {
        verList = new EdgeNode *[n + 1];
        for (int i = 0; i <= n; ++i)
            verList[i] = NULL;
    }
    ~Graph()
    {
        EdgeNode *p, *q;
        for (int i = 0; i <= vertice; ++i)
        {
            p = verList[i];
            while (p)
            {
                q = p;
                p = p->next;
                delete q;
            }
        }
        delete[] verList;
    }
    bool insert(int a, int b, int w);
    int spath(int start, int end) const;
};

bool Graph::insert(int a, int b, int w)
{
    verList[a] = new EdgeNode(b, w, verList[a]);
    ++edge;
    return true;
}

int Graph::spath(int start, int end) const
{
    int *distance, node;
    EdgeNode *tmp;
    queue<int> q;
    distance = new int[vertice + 1];
    for (int i = 1; i <= vertice; ++i)
        distance[i] = INT_MAX;
    distance[start] = 0;
    q.push(start);
    while (q.size())
    {
        node = q.front();
        q.pop();
        tmp = verList[node];
        while (tmp)
        {
            if (distance[tmp->end] > distance[node] + tmp->weight)
            {
                distance[tmp->end] = distance[node] + tmp->weight;
                q.push(tmp->end);
            }
            tmp = tmp->next;
        }
    }
    return distance[end];
}

int main()
{
    int a, b, w, n, m, start, end;
    cin >> n >> m >> start >> end;
    Graph graph(n);
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> w;
        graph.insert(a, b, w);
    }
    cout << graph.spath(start, end);
    return 0;
}