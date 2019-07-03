# include<cstdio>
# include<algorithm>
using namespace std;

struct edge
{
    int a, b, p;
};

bool comp(const edge &a, const edge &b)
{
    return a.p<b.p;
}

int parent[10010];
edge E[100010];

int find(int x)
{
    if(parent[x]<0)
        return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void Union(int x, int y)
{
    int a=find(x), b=find(y);
    if(a!=b)
        parent[a] = b;
}

int main()
{
    int n, m;
    int c;
    long long ans;
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;++i)
        scanf("%d%d%d", &E[i].a, &E[i].b, &E[i].p);
    sort(E, E+m, comp);

    for(int i=1;i<=n;++i)
        parent[i] = -1;
    ans = 0;
    c = 0;
    for(int i=0;i<m;++i)
    {
        if(find(E[i].a)!=find(E[i].b))
        {
            Union(E[i].a, E[i].b);
            ans += E[i].p;
            c+=1;
        }
        if(c>=n-1)
            break;
    }
    printf("%d", ans);
    return 0;
}
