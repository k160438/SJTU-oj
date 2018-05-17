#include <cstdio>
#include <stack>
using namespace std;
#define maxsize 1000005

char tree[maxsize];
int n, timesCount[maxsize];

void countInitial()
{
    for (int i = 0; i < n; ++i)
        timesCount[i] = 0;
}

void encode(int mode)
{
    stack<int> s;
    int i;
    countInitial();
    s.push(1);
    while (s.size())
    {
        i = s.top();
        timesCount[i - 1] += 1;
        s.pop();
        if (timesCount[i - 1] == mode)
            printf("%c", tree[i - 1]);
        else
            s.push(i);
        if (2 * i + 1 <= n)
            s.push(2 * i + 1);
        if (2 * i <= n)
            s.push(2 * i);
    }
    printf("\n");
}



int main()
{
    int t, op;
    char command[10], mode[10];
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        scanf("%d %s %s", &n, mode, command);
        scanf("%s", tree);
        if (command[0] == 'E')
        {
            switch (mode[2])
            {
            case 'O':
                op = 2;
                break;
            case 'E':
                op = 1;
                break;
            default:
                op = 3;
            }
            encode(op);
        }
    }
    return 0;
}