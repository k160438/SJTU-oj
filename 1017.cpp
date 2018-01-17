#include <iostream>
using namespace std;

int main()
{
    int a, b, c, N;
    long long A, B, C, tmp;
    cin >> a >> b >> c >> N;
    N = N + 1;
    if (N == 1)
        cout << 1 << endl;
    if (N == 2)
        cout << a + 1 << endl;
    if (N == 3)
        cout << a * a + b + a + 1 << endl;
    if (N <= 3)
        return 0;
    A = a * a + b;
    B = a;
    C = 1;
    for (int i = N - 3; i > 0; --i)
    {
        tmp = A * a + B * b + C * c;
        C = B + C;
        B = A;
        A = tmp;
        // cout<<N-i<<' '<<A+B+C<<endl;
    }
    cout << A + B + C << endl;
    return 0;
}