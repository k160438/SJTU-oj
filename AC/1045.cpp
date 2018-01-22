#include <iostream>
#include <cstdio>
using namespace std;
#define maxsize 200005

int members[maxsize][3] = {{0}};
//number of sons, his father number, alive

int main()
{
    int n, x, y, res = 1;
    char s;
    cin >> n;
    members[1][2] = 1;
    for (int i = 0; i < n; ++i)
    {
        scanf("%c", &s);
        while (!(s == 'B' || s == 'D'))
            scanf("%c", &s);
        if (s == 'B')
        {
            scanf("%d %d", &x, &y);
            members[x][0] += 1;
            members[y][1] = x;
            members[x][2] = 1;
        }
        else
        {
            scanf("%d", &x);
            if (members[members[x][1]][2])
            {
                res += members[x][0];
                members[members[x][1]][0] -= 1;
            }
            else
                res += members[x][0] - 1;
            printf("%d\n", res);
            members[x][2] = 0;
            members[x][0] = 0;
        }
    }

    return 0;
}