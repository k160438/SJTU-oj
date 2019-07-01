# include <cstdio>
using namespace std;
# define maxsize 200010

int table[maxsize];
int c[maxsize];

int main()
{
    int s, t;
    int a, b;
    int tmp;
    scanf("%d%d", &s, &t);
    for(int i=s;i<=t;++i)
    {
        table[i] = 1;
        c[i] = 1;
    }
    for(int i=s; i<t;++i)
    {
        for(int j=1;j<=100;++j)
        {
            if(i*j%100==0)
            {
                tmp = i*j/100 + i;
                if(tmp>t)
                    break;
                if(table[tmp]<table[i]+1)
                {
                    table[tmp] = table[i]+1;
                    c[tmp] = c[i];
                }
                else
                {
                    if(table[tmp]==table[i]+1)
                        c[tmp]+=c[i];
                }
            }
        }
    }
    a = 0;
    for(int i=s;i<=t;++i)
        if(a<table[i])
            a = table[i];
    b = 0;
    for(int i=s;i<=t;++i)
        if(a==table[i])
            b += c[i];
    printf("%d\n%d", a, b);
    return 0;
}
