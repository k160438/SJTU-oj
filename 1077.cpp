#include <iostream>
using namespace std;
#define maxsize 35

struct Node
{
    int left, right, data;
};

Node tree[maxsize];
int score[maxsize];
int res[maxsize][maxsize];
int n;

void BuildTree(int root)
{
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> score[i];
        cout << i << ' ';
    }
    return 0;
}