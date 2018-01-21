#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct tradedoc
{
    int t, a, d;
};

bool cmp(const tradedoc &a, const tradedoc &b)
{
    return a.t < b.t;
}

int main()
{
    int m, n, i, j, price[10002][2], tmp;
    double res = 0, yongjin = 0;
    tradedoc trades[51];
    cin >> m;
    for (i = 0; i < m; ++i)
        cin >> trades[i].t >> trades[i].a >> trades[i].d;
    sort(trades, trades + m, cmp);
    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> price[i][0] >> price[i][1];
    j = 0;
    for (i = 0; i < m; ++i)
    {
        while (j < n && price[j][0] <= trades[i].t)
            ++j;
        tmp = price[j - 1][1];
        yongjin = tmp * trades[i].a * 0.2;
        if (yongjin < 5)
            yongjin = 5;
        if (trades[i].d & 1)
        {
            res -= trades[i].a * tmp * 100 + 1 + trades[i].a * 0.1 + yongjin;
        }
        else
            res += trades[i].a * tmp * 99.9 - 1 - yongjin - trades[i].a * 0.1;
    }
    //不知道为什么强行截断可以叫四舍五入，怪不得我原来写的四舍五入过不了
    cout << fixed << setprecision(2) << res;
    return 0;
}