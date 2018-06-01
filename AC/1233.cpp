#include <iostream>
#include <stack>
using namespace std;

class Graph
{
    struct edgeNode
    {
        int end;
        edgeNode *next;
        edgeNode(int e, edgeNode *n) : end(e), next(n) {}
    };
    struct verNode
    {
        int id;
        edgeNode *head;
        verNode(edgeNode *n = NULL) : head(n) {}
    };
    int size, edge;
    int covered[11] = {0};
    verNode *verList;

  public:
    Graph(int n) : size(n), edge(0)
    {
        verList = new verNode[n + 1];
        for (int i = 1; i <= n; ++i)
            verList[i].id = i;
    }
    ~Graph()
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

    bool insert(int a, int b);
    int dfs(int start, int m);
    int edg() { return edge; }
};

bool Graph::insert(int a, int b)
{
    Graph::edgeNode *p = verList[a].head;
    while (p)
    {
        if (p->end == b)
            return false;
        p = p->next;
    }
    verList[a].head = new edgeNode(b, verList[a].head);
    ++edge;
    return true;
}

int Graph::dfs(int start, int m)
{
    int ans = 0, node, sth;
    edgeNode *p;
    bool flag;
    stack<int> nodes, step;
    nodes.push(start);
    step.push(0);
    while (nodes.size())
    {
        node = nodes.top();
        nodes.pop();
        sth = step.top();
        step.pop();
        if (sth == m)
        {
            ++ans;
            continue;
        }
        covered[sth] = node;
        p = verList[node].head;
        while (p)
        {
            flag = true;
            for (int i = 0; i < sth + 1; ++i)
                if (p->end == covered[i])
                {
                    flag = false;
                    break;
                }
            if (flag)
            {
                nodes.push(p->end);
                step.push(sth + 1);
            }
            p = p->next;
        }
    }
    return ans;
}

int main()
{
    int n, m, start, M, a, b;
    cin >> n >> m >> start >> M;
    Graph graph(n);
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        graph.insert(a, b);
    }
    cout << graph.dfs(start, M) << endl;
    return 0;
}