#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, num[10000];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> num[i];
    sort(num, num + n);
    for (int i = 0; i < n; ++i)
        cout << num[i] << ' ';
}