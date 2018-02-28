#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define maxsize 100005

struct P
{
    int number, height;
    P() : number(0), height(2147483647) {}
};

P planes[maxsize];
int heapsize, index[maxsize];

bool operator>(const P &a, const P &b)
{
    if (a.height == b.height)
        return a.number > b.number;
    return a.height > b.height;
}

void Heapify(P A[], int i)
{
    P tmp;
    int smallest = i;
    if (2 * i <= heapsize && A[smallest] > A[2 * i])
        smallest = 2 * i;
    if (2 * i + 1 <= heapsize && A[smallest] > A[2 * i + 1])
        smallest = 2 * i + 1;
    if (smallest != i)
    {
        tmp = A[i];
        A[i] = A[smallest];
        A[smallest] = tmp;
        index[A[i].number] = i;
        index[A[smallest].number] = smallest;
        Heapify(A, smallest);
    }
}

void BuildHeap(P A[])
{
    int i = 1, tmp = 0;
    while (tmp < heapsize)
    {
        tmp += i;
        i <<= 1;
    }
    for (i = tmp - i / 2; i >= 1; --i)
        Heapify(A, i);
}

P findmin(int i, int x)
{
    if (i > heapsize)
        return P();
    if (planes[i].height > x)
        return planes[i];
    P left = findmin(i * 2, x);
    P right = findmin(i * 2 + 1, x);
    if (left > right)
        return right;
    else
        return left;
}

void decrease()
{
    int i, j;
    P tmp;
    cin >> i >> j;
    i = index[i];
    planes[i].height -= j;
    while (i > 1 && planes[i / 2] > planes[i])
    {
        tmp = planes[i];
        planes[i] = planes[i / 2];
        planes[i / 2] = tmp;
        index[planes[i].number] = i;
        index[planes[i / 2].number] = i / 2;
        i >>= 1;
    }
}

int main()
{
    int n, i;
    string s;
    cin >> n;
    heapsize = n;
    for (i = 1; i <= n; ++i)
    {
        scanf("%d", &planes[i].height);
        planes[i].number = i;
        index[i] = i;
    }

    BuildHeap(planes);
    while (cin >> s)
    {
        if (s[0] == 'f')
        {
            cin >> n;
            cout << findmin(1, n).number << endl;
        }
        else
            decrease();
    }

    return 0;
}