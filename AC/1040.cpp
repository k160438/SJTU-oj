#include <iostream>
using namespace std;

int tree[1000005][2] = {{0}}, traversal[1000005];
int main()
{
    int n, x, y, head, tail;
    cin >> n;
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> x;
        if (!tree[x][0])
            tree[x][0] = i;
        else
            tree[x][1] = i;
    }
    traversal[0] = 0;
    head = 0;
    tail = 1;
    while (head < tail)
    {
        x = tree[traversal[head]][0];
        y = tree[traversal[head]][1];
        if (x > 0)
            traversal[tail++] = x;
        if (y > 0)
            traversal[tail++] = y;
        cout << traversal[head++] << ' ';
    }
    return 0;
}