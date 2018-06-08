#include <iostream>
using namespace std;

class Network
{
    struct Node
    {
        int parent, adj;
        Node() : parent(-1), adj(0) {}
    };
    int find(int a);
    Node *head;
    int flag;

  public:
    Network(int n) : flag(2)
    {
        head = new Node[n + 1];
    }
    void insert(int a, int b);
    int ans() { return flag; }
};

int Network::find(int a)
{
    int p, tmp = a, ans = a;
    while (head[ans].parent > 0)
        ans = head[ans].parent;
    while (head[tmp].parent > 0)
    {
        p = head[tmp].parent;
        head[tmp].parent = ans;
        tmp = p;
    }
    return ans;
}

void Network::insert(int a, int b)
{
    if (!flag)
        return;
    int x = find(a), y = find(b);
    if (x == y)
    {
        flag = 0;
        return;
    }
    if (head[x].parent < head[y].parent)
    {
        head[x].parent += head[y].parent;
        head[y].parent = x;
    }
    else
    {
        head[y].parent += head[x].parent;
        head[x].parent = y;
    }
    head[a].adj += 1;
    head[b].adj += 1;
    if (head[a].adj > 3 || head[b].adj > 3)
        flag = 1;
}

int main()
{
    int T, n, m, a, b;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> n >> m;
        if (n == m + 1)
        {
            Network net(n);
            for (int j = 0; j < m; ++j)
            {
                cin >> a >> b;
                net.insert(a, b);
            }
            switch (net.ans())
            {
            case 0:
                cout << ".\n";
                break;
            case 1:
                cout << "t\n";
                break;
            default:
                cout << "bt\n";
            }
        }
        else
        {
            for (int j = 0; j < m; ++j)
                cin >> a >> b;
            cout << ".\n";
        }
    }
    return 0;
}