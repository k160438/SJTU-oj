#include <cstdio>
using namespace std;
#define maxsize 10005

struct node
{
    int value, next;
};

node llist[maxsize];

int main()
{
    int n, m, i, j, tmp, head = 0, count = 0;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &llist[i].value);
        llist[i].next = i + 1;
    }
    scanf("%d", &m);
    for (i = 0; i < m; ++i)
    {
        scanf("%d", &tmp);
        ++count;
        if (tmp != llist[head].value)
            for (j = head; llist[j].next < n; j = llist[j].next)
            {
                ++count;
                if (tmp == llist[llist[j].next].value)
                {
                    tmp = head;
                    head = llist[j].next;
                    llist[j].next = llist[llist[j].next].next;
                    llist[head].next = tmp;
                    break;
                }
            }
    }
    printf("%d", count);

    return 0;
}