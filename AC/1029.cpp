#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    queue<string> q[101];
    string s;
    int n, ahead, behind;
    cin >> n;
    cin.get();
    if (n <= 0)
        return 0;
    for (int i = 0; i < n; ++i)
    {
        getline(cin, s);
        q[i].push(s);
    }
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> behind >> ahead;
        while (!q[behind - 1].empty())
        {
            q[ahead - 1].push(q[behind - 1].front());
            q[behind - 1].pop();
        }
    }
    for (int i = 0; i < n; ++i)
        if (!q[i].empty())
        {
            while (!q[i].empty())
            {
                cout << q[i].front() << ' ';
                q[i].pop();
            }
            break;
        }
    return 0;
}