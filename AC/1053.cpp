#include <cstdio>
using namespace std;
#define maxsize 100005

struct element
{
    int row, col, value;
};

element matrix[maxsize];
int row[maxsize], col[maxsize];

int main()
{
    int n, m, op, x, y, tmp;
    bool flag;
    scanf("%d", &n);
    for (int i = 0; i < maxsize; ++i)
    {
        row[i] = i;
        col[i] = i;
    }

    for (int i = 0; i < n; ++i)
        scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d %d", &op, &x, &y);
        if (op == 0)
        {
            tmp = row[x];
            row[x] = row[y];
            row[y] = tmp;
        }
        else
        {
            if (op == 1)
            {
                tmp = col[x];
                col[x] = col[y];
                col[y] = tmp;
            }
            else
            {
                x = row[x];
                y = col[y];
                flag = true;
                for (int j = 0; j < n; ++j)
                    if (matrix[j].row == x && matrix[j].col == y)
                    {
                        printf("%d\n", matrix[j].value);
                        flag = false;
                        break;
                    }
                if (flag)
                    printf("0\n");
            }
        }
    }

    return 0;
}