#include <iostream>
using namespace std;

int main()
{
    long long a[10000], b[10000];
    int count = 0;
    while(cin>>a[count]>>b[count])
    {
        ++count;
    }
    for (int i = 0;i < count;++i)
    {
        cout<<a[i] + b[i] <<'\n';
    }
    return 0;
}