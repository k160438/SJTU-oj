#include <cstdio>
#include <algorithm>
using namespace std;
#define maxsize 505

int height[maxsize][maxsize];
int ans[maxsize][maxsize] = {0};
int r, c;

int dfs(int x, int y)
{
    if (ans[x][y])
        return ans[x][y];
    int longest = 0;
    if (x > 0 && height[x - 1][y] < height[x][y])
        longest = max(longest, dfs(x - 1, y) + 1);
    if (x < r - 1 && height[x + 1][y] < height[x][y])
        longest = max(longest, dfs(x + 1, y) + 1);
    if (y > 0 && height[x][y - 1] < height[x][y])
        longest = max(longest, dfs(x, y - 1) + 1);
    if (y < c - 1 && height[x][y + 1] < height[x][y])
        longest = max(longest, dfs(x, y + 1) + 1);
    if (ans[x][y] < longest)
        ans[x][y] = longest;
    return longest;
}

int main()
{
    int l = 0;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            scanf("%d", &height[i][j]);
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            dfs(i, j);
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (ans[i][j] > l)
                l = ans[i][j];
    ++l;
    printf("%d", l);
    return 0;
}