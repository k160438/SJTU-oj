#include <iostream>
#include <string>
using namespace std;

int main()
{
    string clear, cipher;
    int a, b, i, j;
    bool flag;
    cin >> clear >> cipher;
    if (clear.size() != cipher.size())
        cout << "No Solution";
    else
    {
        a = 1;
        while (++a <= clear.size())
            if (clear.size() % a == 0)
            {
                b = clear.size() / a;
                flag = true;
                for (i = 1; i <= a; ++i)
                    if (flag)
                    {
                        for (j = 1; j <= b; ++j)
                            if (cipher[i * b - b + j - 1] != clear[j * a - a + i - 1])
                            {
                                flag = false;
                                break;
                            }
                    }
                    else
                        break;
                if (i > a)
                {
                    cout << a;
                    return 0;
                }
            }
        cout << "No Solution";
    }
    return 0;
}