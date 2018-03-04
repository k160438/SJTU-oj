#include <cstdio>
using namespace std;
#define maxsize 10005

int girls[maxsize] = {0}, n;

int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int delta)
{
    while (x <= n)
    {
        girls[x] += delta;
        x += lowbit(x);
    }
}

int query(int x)
{
    int res = 0;
    while (x > 0)
    {
        res += girls[x];
        x -= lowbit(x);
    }
    return res;
}

int main()
{
    int tmp, x, y;
    char command[20];
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &tmp);
        update(i, tmp);
    }
    scanf("%s", command);
    while (command[0] != 'e')
    {
        scanf("%d %d", &x, &y);
        if (command[0] == 'q')
            printf("%d\n", query(y) - query(x - 1));
        else if (command[0] == 'i')
            update(x, y);
        else
            update(x, -y);
        scanf("%s", command);
    }
    return 0;
}