#include <iostream>
using namespace std;

int hash_tab[200000] = {0};

void find_longest_seq(int s, int t, int length, int res[])
{
    hash_tab[s - 1] = 1;
    for (int i = 1; i <= 100; ++i)
    {
        if (((s * i) % 100) == 0)
        {
            if (s + s * i / 100 < t)
            {
                hash_tab[s + s * i / 100 - 1] = 1;
                find_longest_seq(s + s * i / 100, t, length + 1, res);
            }
            else
            {
                if (s + s * i / 100 == t)
                    length += 1;
                if (length == res[0])
                    res[1] += 1;
                if (length > res[0])
                {
                    res[0] = length;
                    res[1] = 1;
                }
                return;
            }
        }
    }
}

int main()
{
    int res[2] = {0, 0};
    int s, t;
    cin >> s >> t;
    for (int i = s; i <= t; ++i)
        if (hash_tab[i - 1] == 0)
        {
            find_longest_seq(i, t, 1, res);
        }
    cout << res[0] << '\n'
         << res[1];
    return 0;
}