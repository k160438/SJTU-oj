#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    int N, sqrtN, tmp, count, i, k;
    bool prime[46400] = {false};
    cin >> N;
    tmp = N;
    sqrtN = sqrt(N);
    cout<<N<<'=';
    for (i = 2; i <= sqrtN && i <= tmp; ++i)
    {
        if (!prime[i])
        {
            count = 0;
            while (tmp % i == 0)
            {
                tmp /= i;
                ++count;
            }
            if (count > 0)
            {
                cout<<i<<'('<<count<<')';
            }
            k = 2;
            while (k * i <= sqrtN && k * i <= tmp)
            {
                prime[k * i] = true;
                ++k;
            }
        }
    }
    if (tmp > 1)
        cout << tmp<<"(1)";
    return 0;
}