#include <iostream>
#include <queue>
using namespace std;
#define maxsize 1030

int tree[maxsize], index[maxsize];
int doc[maxsize] = {0}, nodes[maxsize][2];
queue<int> q;

int main()
{
    int n, a, b, c, root, i;
    cin >> n;
    for (i = 0; i < n / 2; ++i)
    {
        cin >> a >> b >> c;
        nodes[a][0] = b;
        nodes[a][1] = c;
        doc[b] = 1;
        doc[c] = 1;
    }
    for (i = 1; i <= n; ++i)
        if (!doc[i])
        {
            root = i;
            break;
        }
    index[root] = 1;
    tree[1] = root;
    q.push(root);
    while (q.size())
    {
        a = q.front();
        q.pop();
        b = nodes[a][0];
        c = nodes[a][1];
        index[b] = index[a] * 2;
        index[c] = index[a] * 2 + 1;
        tree[index[b]] = b;
        tree[index[c]] = c;
        if (nodes[b][0])
            q.push(b);
        if (nodes[c][0])
            q.push(c);
    }
    for (i = 1; i <= n; ++i)
        cout << tree[i] << '\n';

    return 0;
}