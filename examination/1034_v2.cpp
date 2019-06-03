# include <iostream> 
using namespace std;
#define maxsize 400010

int a[maxsize];
int N, K;

bool judge(int ans)
{
    int count = 0;
    for(int i=0;i<N+K;++i)
    {
        if(a[i] <= ans)
            ++count;
        else
        {
            count=0;
        }
        if(count>=K)
            return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    int l = 0, r=0, mid;
    cin>>N>>K;
    for(int i=0;i<N;++i)
    {
        cin>>a[i];
        a[i+N] = a[i];
        if(r<a[i])
            r = a[i];
    }

    while (l<r)
    {
        mid = (l+r)/2;
        if(judge(mid))
            r = mid;
        else
        {
            l = mid;
        }

        if(r==l+1)
            break;
    }
    
    cout<<r<<endl;
    return 0;
}