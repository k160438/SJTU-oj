#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct firetruck
{
    int a;
    int b;
};

bool comp(const firetruck &a, const firetruck &b)
{
    return a.a < b.a;                    //亲测这里不可以加等号
}

int main()
{
    vector<firetruck> f;
    firetruck tmp;
    int n, left, right, res = 0;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp.a >> tmp.b;
        f.push_back(tmp);
    }
    sort(f.begin(), f.end(), comp);
    left = f[0].a;
    right = f[0].b;
    for (int i = 1; i < n; ++i)
        if (f[i].a > right)
        {
            res += right - left;
            left = f[i].a;
            right = f[i].b;
        }
        else
        {
            if (f[i].b > right)
                right = f[i].b;
        }
    res += right - left;
    cout << res;
    return 0;
}