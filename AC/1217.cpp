#include<cstdio> 
#include<algorithm>
using namespace std;
#define maxsize 2502

int n, table[maxsize], m, tmp;

int main()
{
    int i, l, r, mid;
    scanf("%d", &n);
    for(i=0;i<n;++i)
    scanf("%d", &table[i]);
    sort(table, table + n);
    scanf("%d", &m);
    for(i=0;i<m;++i)
    {
        scanf("%d", &tmp);
        l = 0;
        r = n - 1;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(table[mid] == tmp)
            {
                printf("Y\n");
                break;
            }
            else
            if(table[mid]<tmp)
            l = mid + 1;
            else
            r = mid - 1;
        }
        if(l>r)
        printf("N\n");
    }
    return 0;
}