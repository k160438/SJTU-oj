# include <cstdio>
# define maxsize 11010
using namespace std;

int table[maxsize][1005];
int value[maxsize], weight[maxsize];

int main()
{
    int n, m;
    int num=0, p, w, v;
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;++i)
    {
        scanf("%d%d%d", &p, &w, &v);
        int k;
        while(p>0)
        {
            k = p>>1;
            if(k==0)
                k = p;
            p -= k;
            value[++num] = k*v;
            weight[num] = k*w;
        }
    }
    for(int i=0;i<=num;++i)
        table[i][0] = 0;
    for(int j=0;j<=m;++j)
        table[0][j] = 0;
    for(int i =1;i<=num;++i)
        for(int j=1;j<=m;++j)
        {
            table[i][j] = table[i-1][j];
            if(j>=weight[i] && table[i][j]<table[i-1][j-weight[i]]+value[i])
                table[i][j] = table[i-1][j-weight[i]]+value[i];
        }
    printf("%d", table[num][m]);
    return 0;
}
