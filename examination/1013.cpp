# include <cstdio>
# define maxsize 10010
using namespace std;

int table[1010][maxsize];
int volume[1010],value[1010];

int main()
{
    int v, n;
    scanf("%d %d", &v, &n);
    for(int i=1;i<=n;++i)
        scanf("%d%d", &volume[i], &value[i]);

    for(int i=0;i<=n;++i)
        table[i][0] = 0;
    for(int i=0;i<=v;++i)
        table[0][i] = 0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=v;++j)
        {
            table[i][j] = table[i-1][j];
            if(j>=volume[i] && table[i][j-volume[i]] + value[i]>table[i][j])
                table[i][j] = table[i][j-volume[i]] + value[i];
        }
    printf("%d", table[n][v]);
    return 0;
}
