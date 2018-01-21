#include <iostream>
#include <queue>
using namespace std;
#define maxsize 1000005

int index[maxsize], nodes[maxsize][2] = {{0}};
queue<int> q;

int main()
{
    int n, x, y;
    cin >> n;
    index[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        cin >> x;
        if (nodes[x][0] == 0)
            nodes[x][0] = i;
        else
            nodes[x][1] = i;
    }
    q.push(0);
    while (q.size())
    {
        x = q.front();
        q.pop();
        if (nodes[x][0])
        {
            y = 2 * index[x];
            if (y > n)
            {
                cout << "false";
                return 0;
            }
            q.push(nodes[x][0]);
            index[nodes[x][0]] = y;
            if (nodes[x][1])
            {
                y = 2 * index[x] + 1;
                if (y > n)
                {
                    cout << "false";
                    return 0;
                }
                q.push(nodes[x][1]);
                index[nodes[x][1]] = y;
            }
        }
    }
    cout << "true";

    return 0;
}