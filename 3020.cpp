#include <cstdio>
#include <queue>
using namespace std;
#define maxsize 100005

priority_queue<int, vector<int>, greater<int> > q;

int main()
{
    int n, m, k, newnode, tmp;
    long long ans = 0;
    scanf("%d %d", &n, &m);
    k = (n - 1) % (m - 1);
    if (k != 0)
        k = m - 1 - k;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        q.push(tmp);
    }
    for (int i = n; i < n + k; ++i)
        q.push(0);
    n += k;
    while (n > 1)
    {
        newnode = 0;
        for (int i = 0; i < m; ++i)
        {
            newnode += q.top();
            q.pop();
        }
        ans += newnode;
        q.push(newnode);
        n -= m-1;
    }
    printf("%lld", ans);
    return 0;
}