#include <iostream>
#include <string.h>
using namespace std;

int islawful(char s[])
{
    int flag = 0, length = strlen(s);
    if (length % 2 > 0)
        return 0;
    for (int i = 0; i < length; ++i)
    {
        if (s[i] == '(')
            ++flag;
        else
            --flag;
        if (flag < 0)
            return 0;
    }
    if (flag != 0)
        return 0;
    else
        return 1;
}

int main()
{
    int n, res[50];
    char s[105];
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin.get();
        cin.get(s, 102, '\n');
        res[i] = islawful(s);
    }
    for (int i = 0; i < n; ++i)
        cout << (res[i]>0?"YES":"NO") << '\n';
    return 0;
}