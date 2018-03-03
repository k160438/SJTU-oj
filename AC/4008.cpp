#include <iostream>
#include <string.h>
using namespace std;
#define maxsize 103

void run(char a[], char b[])
{
    char res[maxsize];
    int alen = strlen(a), blen = strlen(b);
    int jinwei = 0, k = 0;
    while (alen > 0 && blen > 0)
    {
        res[k++] = 'a' + (a[--alen] + b[--blen] - 'a' - 'a' + jinwei) % 26;
        jinwei = (a[alen] + b[blen] - 'a' - 'a' + jinwei) / 26;
    }
    while (alen > 0)
    {
        res[k++] = 'a' + (a[--alen] - 'a' + jinwei) % 26;
        jinwei = (a[alen] - 'a' + jinwei) / 26;
    }
    while (blen > 0)
    {
        res[k++] = 'a' + (b[--blen] - 'a' + jinwei) % 26;
        jinwei = (b[blen] - 'a' + jinwei) / 26;
    }
    if (jinwei)
        res[k++] = 'a' + jinwei;
    while (k > 0)
        cout << res[--k];
}

int main()
{
    char a[maxsize], b[maxsize];
    cin >> a >> b;
    run(a, b);
    return 0;
}