# include <iostream> 
using namespace std;
# define maxsize 105000
// luoyuan de hafuman shu

int heap[maxsize];
int heapsize;
// index start from 1
int pop()
{
    if(heapsize==0)
        return 0;
    int res = heap[1], tmp, t;
    heap[1] = heap[heapsize--];
    for(int i=1;i*2<=heapsize;)
    {
        tmp = i;
        if(heap[i]>=heap[2*i])
            tmp = 2*i;
        if(i*2+1<=heapsize && heap[tmp]>=heap[2*i+1])
            tmp = 2*i+1;
        if(tmp == i)
            break;
        else
        {
            t = heap[tmp];
            heap[tmp] = heap[i];
            heap[i] = t;
            i = tmp;
        }
    }
    return res;
}

void insert(int x)
{
    heap[++heapsize] = x;
    for(int i=heapsize;i>1;)
    {
        if(heap[i]<heap[i>>1])
        {
            int tmp;
            tmp = heap[i];
            heap[i] = heap[i>>1];
            heap[i>>1] = tmp;
            i = i >> 1;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int m, n, f;
    long long ans = 0;
    
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        cin>>f;
        insert(f);
    }
    f = (n-1)%(m-1);
    if(f!=0)
        f = m-1-f;
    for(int i=0;i<f;++i)
        insert(0);
    while (heapsize>1)
    {
        // cout<<'h'<<heapsize<<'\n';
        f = 0;
        // cout<<heap[1]<<'_'<<heap[2]<<'_'<<heap[3]<<'_'<<heap[4]<<'\n';
        for(int i=0;i<m;++i)
            f += pop();
        
        ans += f;
        insert(f);
    }
    cout<<ans<<endl;
    return 0;
}