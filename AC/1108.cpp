#include <iostream>
#include <stack>
using namespace std;
#define maxsize 102

int matrix[maxsize][maxsize] = {0};
int n;

int search(int a, int b)
{
    int x, y;
    bool covered[maxsize] = {0};
    stack<int> path, length;
    covered[a] = 1;
    for (int j = 1; j <= n; ++j)
        if (matrix[a][j])
        {
            path.push(j);
            length.push(matrix[a][j]);
        }
    while (path.size())
    {
        x = path.top();
        path.pop();
        y = length.top();
        length.pop();
        if (x == b)
            return y;
        covered[x] = 1;
        for (int i = 1; i <= n; ++i)
            if (matrix[x][i] > 0 && covered[i] == 0)
            {
                path.push(i);
                length.push(y + matrix[x][i]);
            }
    }
    return 0;
}

int main()
{
    int m, a, b, w;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b >> w;
        matrix[a][b] = w;
        matrix[b][a] = w;
    }
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        w = search(a,b);
        w = w>0?w:search(b,a);
        cout<<w<<'\n';
    }

    return 0;
}