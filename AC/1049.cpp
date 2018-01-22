#include <cstdio>
using namespace std;
#define maxsize 1005

int trains[maxsize], stored[maxsize];

int main()
{
    int T, n, m, i, j, depart, store;
    bool flag;
    scanf("%d", &T);
    for (i = 0; i < T; ++i)
    {
        scanf("%d %d", &n, &m);
        for (j = 0; j < n; ++j)
            scanf("%d", &trains[j]);
        depart = 0;
        store = -1;
        flag = true;
        for (j = 0; j < n; ++j)
        {
            while (store >= 0)
            {
                if (trains[depart] == stored[store])
                {
                    ++depart;
                    --store;
                }
                else
                    break;
            }
            if (trains[depart] == j)
                ++depart;
            else
            {
                if (store < m - 1)
                    stored[++store] = j;
                else
                {
                    flag = false;
                    break;
                }
            }
        }

        while (store >= 0)
        {
            if (trains[depart] == stored[store])
            {
                ++depart;
                --store;
            }
            else
                break;
        }
        if (depart != n)
            flag = false;
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}