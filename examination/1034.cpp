#include <iostream>
using namespace std;
#define maxsize 400010

int a[maxsize];
int queue[maxsize]; // only store the index
int head=0, tail=0;

void queueAppend(int index)
{
    if(head == tail)
    {
        queue[tail++] = index;
        return ;
    }
    for(int j=tail-1;j>=head;--j)
    {
        if(a[queue[j]]<=a[index])
            --tail;
        else
        {
            break;
        }
    }
    queue[tail++] = index;
}

int main()
{
    int N, K;
    int ans;
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
        a[N + i] = a[i];
    }


    for(int i=0;i<K;++i)
    {
        queueAppend(i);
    }
    ans = a[queue[head]];
    for(int j=K;j<N+K;++j)
    {
        if(queue[head]<j-K+1)
            ++head;
        queueAppend(j);
        if(a[queue[head]]<ans)
            ans = a[queue[head]];
    }
    cout<<ans<<endl;
    return 0;
}