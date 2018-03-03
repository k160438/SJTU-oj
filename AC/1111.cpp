#include <iostream>
#include <string>
using namespace std;
#define maxsize 1005

void buildTreee(char tree[], int node, string preorder, string inorder)
{
    tree[node] = preorder[0];
    if (preorder.length() == 1)
        return;
    int mid = 0;
    char root = preorder[0];
    while (inorder[mid] != root)
    {
        ++mid;
    }
    if (mid > 0)
        buildTreee(tree, 2 * node, preorder.substr(1, mid), inorder.substr(0, mid));
    if (mid < preorder.length() - 1)
        buildTreee(tree, 2 * node + 1, preorder.substr(1 + mid, preorder.length() - 1 - mid), inorder.substr(mid + 1, inorder.length() - 1 - mid));
}

int main()
{
    char tree[maxsize] = {0};
    string preorder, inorder;
    int n, i = 1;
    cin >> preorder >> inorder;
    n = preorder.length();
    buildTreee(tree, 1, preorder, inorder);
    while (n > 0)
    {
        if (tree[i] > 0)
        {
            cout << tree[i] << ' ';
            --n;
        }
        else
            cout << "NULL" << ' ';
        ++i;
    }
    return 0;
}