# include<cstdio>
# include<vector>
# include<queue>
using namespace std;
# define maxsize 10010

struct edge
{
    int end, weight;
    edge(int a, int b):end(a), weight(b){}
};

struct node
{
    int num, dist;
    node(int a=0, int b=0):num(a), dist(b){}
    bool operator<(const node &a)const
    {
        return dist<a.dist;
    }
    bool operator>(const node &a)const
    {
        return dist>a.dist;
    }
};

vector<edge> adjacent[maxsize];
int parent[maxsize];
int dist[maxsize];
int num_dist[maxsize];
int prevent[maxsize];
int path[maxsize];

int find(int x)
{
    if(parent[x]<0)
        return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void Union(int x, int y)
{
    int a=find(x), b = find(y);
    if(a!=b)
        parent[a] = b;
}

void printf_path(int end)
{
    int c = 0, i=end;
    while(i>0)
    {
        path[c++] = i;
        i = prevent[i];
    }
    for(i=c-1;i>=0;--i)
        printf("%d ", path[i]);
}

int main()
{
    int n, m, start, end;
    int a, b, p;
    priority_queue<node, std::vector<node>, greater<node>> pq;
    scanf("%d%d%d%d", &n, &m, &start, &end);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d%d", &a, &b, &p);
        adjacent[a].push_back(edge(b, p));
    }

    for(int i=1;i<=n;++i)
    {
        parent[i] = -1;
        dist[i] = -1;
        num_dist[i] = 10001;
    }

    dist[start] = 0;
    num_dist[start] = 0;
    prevent[start] = 0;

    pq.push(node(start, dist[start]));
    while(pq.size())
    {
        a = pq.top().num;
        b = pq.top().dist;
        if(a==end)
            break;
        pq.pop();
        Union(start, a);
        for(int i=0;i<adjacent[a].size();++i)
        {
            if(find(start)==find(adjacent[a][i].end))
                continue;
            if(dist[adjacent[a][i].end]<0 || dist[adjacent[a][i].end]>b+adjacent[a][i].weight)
            {
                dist[adjacent[a][i].end] = b+adjacent[a][i].weight;
                prevent[adjacent[a][i].end] = a;
                num_dist[adjacent[a][i].end] = num_dist[a]+1;
                pq.push(node(adjacent[a][i].end, dist[adjacent[a][i].end]));
            }else
            {
                if(dist[adjacent[a][i].end]==b+adjacent[a][i].weight)
                {
                    if(num_dist[adjacent[a][i].end]>num_dist[a]+1)
                    {
                        num_dist[adjacent[a][i].end] = num_dist[a]+1;
                        prevent[adjacent[a][i].end] = a;
                    }
                }
            }
        }
    }
    printf("%d\n", dist[end]);
    printf_path(end);
    return 0;
}
