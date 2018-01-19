#include <iostream>
using namespace std;

//模拟链表
int main()
{
    int M, K[10000], monkey[10001], m, i, p, tmp;
    cin >> M;
    m = M;
    for (i = 0; i < M - 1; ++i)
    {
        cin >> K[i];
        monkey[i] = i + 1;
    }
    monkey[M - 1] = 0;
    p = M - 1;
    for (i = 0; i < M - 1; ++i)
    {
        tmp = K[i] % m--;
        if (tmp == 0)
            tmp = m + 1;
        while (--tmp > 0)
        {
            p = monkey[p];
        }
        monkey[p] = monkey[monkey[p]];
    }
    cout << monkey[p] + 1;
    return 0;
}