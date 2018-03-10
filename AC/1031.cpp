#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
#define maxsize 102

//tip：二分答案，而且将猜测的高度差转化为枚举路径的最高和最低高度，从而极大简化搜索过程

int mountain[maxsize][maxsize];
bool covered[maxsize][maxsize];
int n, highest = 0, lowest = 111;

bool bfs(int up_bound, int low_bound)
{
    if (mountain[0][0] > up_bound || mountain[0][0] < low_bound)
        return false;
    memset(covered, false, sizeof(covered));
    covered[0][0] = true;
    queue<pair<int, int> > q;
    q.push(pair<int, int>(0, 0));
    while (q.size())
    {
        int x, y;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (x == n - 1 && y == n - 1)
            return true;
        if (x > 0 && !covered[x - 1][y] && mountain[x - 1][y] >= low_bound && mountain[x - 1][y] <= up_bound)
        {
            q.push(pair<int, int>(x - 1, y));
            covered[x - 1][y] = true;
        }
        if (x < n - 1 && !covered[x + 1][y] && mountain[x + 1][y] >= low_bound && mountain[x + 1][y] <= up_bound)
        {
            q.push(pair<int, int>(x + 1, y));
            covered[x + 1][y] = true;
        }
        if (y > 0 && !covered[x][y - 1] && mountain[x][y - 1] >= low_bound && mountain[x][y - 1] <= up_bound)
        {
            q.push(pair<int, int>(x, y - 1));
            covered[x][y - 1] = true;
        }
        if (y < n - 1 && !covered[x][y + 1] && mountain[x][y + 1] >= low_bound && mountain[x][y + 1] <= up_bound)
        {
            q.push(pair<int, int>(x, y + 1));
            covered[x][y + 1] = true;
        }
    }
    return false;
}

int BinaryFind()
{
    int l = 0, r = highest - lowest, mid;
    bool flag;
    while (l < r)
    {
        flag = false;
        mid = (l + r) >> 1;
        for (int i = lowest; i <= highest - mid; ++i)
            if (bfs(i + mid, i))
            {
                flag = true;
                break;
            }
        if (flag)
            r = mid;
        else
            l = mid + 1;
    }
    return (l + r) >> 1;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> mountain[i][j];
            if (mountain[i][j] > highest)
                highest = mountain[i][j];
            if (mountain[i][j] < lowest)
                lowest = mountain[i][j];
        }
    cout << BinaryFind();
    return 0;
}