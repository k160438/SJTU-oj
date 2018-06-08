#include <cstdio>
#include <queue>
using namespace std;

class Courses
{
    struct Edge;
    struct Node
    {
        int pre;
        Edge *head;
        Node() : pre(0), head(NULL) {}
    };
    struct Edge
    {
        int end;
        Edge *next;
        Edge(int e, Edge *p) : end(e), next(p) {}
    };
    Node *verList;
    int restClass;

  public:
    Courses(int n) : restClass(n)
    {
        verList = new Node[n + 1];
    }
    void insert(int a, int b);
    int solve();
};

void Courses::insert(int a, int b)
{
    verList[a].pre++;
    verList[b].head = new Edge(a, verList[b].head);
}

int Courses::solve()
{
    queue<int> node, term;
    int id, t;
    Edge *p;
    for (int i = 1; i <= restClass; ++i)
        if (!verList[i].pre)
        {
            node.push(i);
            term.push(1);
        }
    while (node.size())
    {
        id = node.front();
        node.pop();
        t = term.front();
        term.pop();
        p = verList[id].head;
        while (p)
        {
            verList[p->end].pre--;
            if (!verList[p->end].pre)
            {
                node.push(p->end);
                term.push(t + 1);
            }
            p = p->next;
        }
    }
    return t;
}

int main()
{
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    Courses MyClass(n);

    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d", &a, &b);
        MyClass.insert(a, b);
    }
    printf("%d", MyClass.solve());
    return 0;
}