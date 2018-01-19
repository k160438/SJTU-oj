#include <iostream>
#include <algorithm>
using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    int N, shares[20002], K, x, y;
    pair<int, int> vec[20002];
    char s;
    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> shares[i];
    cin >> K;
    for (int i = 0; i < K; ++i)
    {
        cin >> s;
        if (s == 'Q')
        {
            for (int j = 0; j < N; ++j)
            {
                vec[j].first = j + 1;
                vec[j].second = shares[j];
            }
            sort(vec, vec + N, comp);
            cin >> x;
            for (int j = 0; j < x; ++j)
            {
                cin >> y;
                cout << vec[y - 1].first << ' ';
            }
            cout << '\n';
        }
        if (s == 'M')
        {
            cin >> x >> y;
            shares[x - 1] = y;
        }
    }
    return 0;
}