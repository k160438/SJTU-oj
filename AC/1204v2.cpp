#include <iostream>
#include <string.h>
using namespace std;
#define maxsize1 105
#define maxsize2 2005

char contents[maxsize1][maxsize2];
char s[maxsize2];
int m, n, rows = 0;

void list()
{
    cin >> m >> n;
    if (m > n || m < 1 || n > rows)
        cout << "Error!" << '\n';
    else
    {
        for (int i = m - 1; i < n; ++i)
            cout << contents[i] << '\n';
    }
}

void ins()
{
    int len, slen;
    cin >> m >> n;
    cin.get();
    cin.getline(s, 2002);
    if (m < 1 || m > rows || n < 1 || n > (len = strlen(contents[m - 1])) + 1)
        cout << "Error!" << '\n';
    else
    {
        slen = strlen(s);
        for (int i = len; i >= n - 1; --i)
            contents[m - 1][i + slen] = contents[m - 1][i];
        for (int i = 0; i < slen; ++i)
            contents[m - 1][i + n - 1] = s[i];
    }
}

void del()
{
    int num, len;
    cin >> m >> n >> num;
    if (m < 1 || m > rows || n < 1 || num < 0|| n > (len=strlen(contents[m-1])) || n + num > strlen(contents[m - 1]) + 1)
        cout << "Error!" << "\n";
    else
    {
        for(int i=n-1+num;i<=len;++i)
        contents[m-1][i-num] = contents[m-1][i];
    }
}

int main()
{
    char tmp;
    cin.getline(s, 2002);
    while (strcmp(s, "******") != 0)
    {
        strcpy(contents[rows++], s);
        cin.getline(s, 2002);
    }

    cin >> s;
    while (strcmp(s, "quit") != 0)
    {
        if (strcmp(s, "list") == 0)
            list();
        else if (strcmp(s, "del") == 0)
            del();
        else if (strcmp(s, "ins") == 0)
            ins();
        cin >> s;
    }
    for (int i = 0; i < rows; ++i)
        cout << contents[i] << '\n';
    return 0;
}