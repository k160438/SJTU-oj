#include <iostream>
using namespace std;

int index[30002], tree[70000] = {0};
int traversal[30002];
int main()
{
    int n, x, y, z, j = 0;
    cin >> n;
    index[1] = 1;
    tree[1] = 1;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y >> z;
        tree[index[x] * 2] = y;
        if (y > 0)
            index[y] = index[x] * 2;
        tree[index[x] * 2 + 1] = z;
        if (z > 0)
            index[z] = index[x] * 2 + 1;
    }
    for (int i = 1; i <= n; ++i)
        cout << index[i] << ' ';
    cout << '\n';
    traversal[0] = 1;
    while (j >= 0)
    {
        x = tree[index[traversal[j]] * 2];
        y = tree[index[traversal[j]] * 2 + 1];
        if (x < 0 && y < 0)
        {
            cout << traversal[j] << ' ';
            tree[index[traversal[j--]]] = -1;
        }
        else
        {
            if (y > 0)
            {
                ++j;
                traversal[j] = y;
            }
            if (x > 0)
            {
                ++j;
                traversal[j] = x;
            }
        }
    }
    return 0;
}