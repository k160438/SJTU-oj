#include <iostream>
using namespace std;

int a[400005], que[200005];

int main()
{
    int N, K;
    int i, j, global_min, head = 0, tail = 0;
    bool flag;
    cin >> N >> K;
    for (i = 0; i < N; ++i)
    {
        scanf("%d", &a[i]);
        a[i + N] = a[i];
    }
    que[0] = 0;
    for (i = 1; i < K; ++i)
    {
        flag = true;
        while (a[i] >= a[que[tail]])
        {
            if (tail == head)
            {
                tail = head;
                que[head] = i;
                flag = false;
                break;
            }
            else
                --tail;
        }
        if (flag)
            que[++tail] = i;
    }
    global_min = a[que[head]];
    for (i = 1; i < N; ++i)
    {
        j = i + K - 1;
        if (que[head] < i)
            ++head;
        flag = true;
        while (a[j] >= a[que[tail]])
        {
            if (tail == head)
            {
                tail = head;
                que[head] = j;
                flag = false;
                break;
            }
            else
                --tail;
        }
        if (flag)
            que[++tail] = j;
        global_min = global_min > a[que[head]] ? a[que[head]] : global_min;
    }
    cout << global_min;
    return 0;
}