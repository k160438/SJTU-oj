#include <iostream>
#include <stack>
using namespace std;

class BinaryTree
{
    struct Node
    {
        int ID;
        Node *left, *right;
        Node(int i, Node *l, Node *r) : ID(i), left(l), right(r) {}
    };
    Node *root;
    int *path_x, *path_y;

    void destroy(Node *root)
    {
        if (!root)
            return;
        destroy(root->left);
        destroy(root->right);
        delete root;
    }
    bool findPath(const Node *root, int id, int level, int *path);

  public:
    BinaryTree(int num)
    {
        path_x = new int[num];
        path_y = new int[num];
    }
    ~BinaryTree()
    {
        destroy(root);
        delete[] path_x;
        delete[] path_y;
    }

    void create(int root, int **Array);
    int lca(int x, int y);
};

void BinaryTree::create(int r, int **Array)
{
    stack<Node *> s;
    Node *tmp;
    root = new Node(r, NULL, NULL);
    s.push(root);
    while (s.size())
    {
        tmp = s.top();
        s.pop();
        if (Array[tmp->ID][0])
        {
            tmp->left = new Node(Array[tmp->ID][0], NULL, NULL);
            s.push(tmp->left);
        }
        if (Array[tmp->ID][1])
        {
            tmp->right = new Node(Array[tmp->ID][1], NULL, NULL);
            s.push(tmp->right);
        }
    }
}

bool BinaryTree::findPath(const Node *root, int id, int level, int *path)
{
    if (!root)
        return false;
    if (root->ID == id)
    {
        path[level] = root->ID;
        return true;
    }
    if (findPath(root->left, id, level + 1, path) || findPath(root->right, id, level + 1, path))
    {
        path[level] = root->ID;
        return true;
    }
    else
        return false;
}

int BinaryTree::lca(int x, int y)
{
    findPath(root, x, 0, path_x);
    findPath(root, y, 0, path_y);
    int i = 1;
    while(path_x[i]==path_y[i])++i;
    return path_x[i-1];
}

int main()
{
    int n, x, y, root;
    int **data, *findroot;
    cin >> n >> x >> y;
    data = new int *[n + 1];
    findroot = new int[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        findroot[i] = 0;
        data[i] = new int[2];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> data[i][0] >> data[i][1];
        findroot[data[i][0]] = 1;
        findroot[data[i][1]] = 1;
    }
    for (int i = 1; i <= n; ++i)
        if (!findroot[i])
        {
            root = i;
            break;
        }

    BinaryTree tree(n);
    tree.create(root, data);
    cout<<tree.lca(x,y);
    return 0;
}