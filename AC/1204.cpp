#include <iostream>
#include <string>
using namespace std;

string contents[101];
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
    string tmp;
    cin >> m >> n;
    cin.get();
    getline(cin, tmp);
    if (m < 1 || m > rows || n < 1 || n > contents[m - 1].size() + 1)
        cout << "Error!" << '\n';
    else
    {
        contents[m - 1].insert(n - 1, tmp);
    }
}

void del()
{
    int num;
    cin >> m >> n >> num;
    if (m < 1 || m > rows || n < 1 || num < 1 || n + num > contents[m - 1].size() + 1)
        cout << "Error!"
             << "\n";
    else
    {
        contents[m - 1].erase(n - 1, num);
    }
}

int main()
{
    string s;
    getline(cin, s);
    while (s != "******")
    {
        contents[rows++] = s;
        getline(cin, s);
    }
    cin >> s;
    while (s != "quit")
    {
        if (s == "list")
            list();
        else if (s == "del")
            del();
        else if (s == "ins")
            ins();
        cin >> s;
    }
    for (int i = 0; i < rows; ++i)
        cout << contents[i] << '\n';
    return 0;
}