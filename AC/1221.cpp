#include <cstdio>
#include <cstring>
using namespace std;

class BST
{
    struct Node
    {
        int data;
        Node *left, *right;
        Node(const int i, Node *l, Node *r) : data(i), left(l), right(r) {}
    };

    Node *root;
    int num_ith, count;

    void delTree(Node *root);
    void insert(const int x, Node *&root);
    void del(const int x, Node *&root);
    void delLess(const int x, Node *&root);
    void delGreater(const int x, Node *&root);
    void delInterval(const int a, const int b, Node *&root);
    bool find(const int x, const Node *root);
    void find_ith(const int i, const Node *root);
    void traversal(const Node *root);

  public:
    BST() : root(NULL) {}
    void insert(const int x) { insert(x, root); }
    void del(const int x) { del(x, root); }
    void delLess(const int x) { delLess(x, root); }
    void delGreater(const int x) { delGreater(x, root); }
    void delInterval(const int a, const int b) { delInterval(a, b, root); }
    void find(const int x);
    void find_ith(const int i);

    void traversal(){traversal(root);}
};

void BST::traversal(const Node *root)
{
    if(!root) return ;
    traversal(root->left);
    printf("%d ", root->data);
    traversal(root->right);
}

void BST::delTree(Node *root)
{
    if (!root)
        return;
    delTree(root->right);
    delTree(root->left);
    delete root;
}

void BST::insert(const int x, Node *&root)
{
    if (!root)
        root = new Node(x, NULL, NULL);
    else if (x < root->data)
        insert(x, root->left);
    else
        insert(x, root->right);
}

void BST::del(const int x, Node *&root)
{
    if (!root)
        return;

    Node *tmp;
    if (root->data == x)
    {
        if (root->right && root->left)
        {
            tmp = root->right;
            while (tmp->left)
                tmp = tmp->left;
            root->data = tmp->data;
            del(tmp->data, root->right);
        }
        else
        {
            tmp = root;
            root = (root->left) ? root->left : root->right;
            delete tmp;
        }
    }
    else if (root->data < x)
        del(x, root->right);
    else
        del(x, root->left);
}

void BST::delLess(const int x, Node *&root)
{
    if (!root)
        return;
    if (x > root->data)
    {
        Node *tmp = root;
        delTree(root->left);
        root = root->right;
        delete tmp;
        delLess(x, root);
    }
    else
        delLess(x, root->left);
}
void BST::delGreater(const int x, Node *&root)
{
    if (!root)
        return;
    if (x < root->data)
    {
        Node *tmp = root;
        delTree(root->right);
        root = root->left;
        delete tmp;
        delGreater(x, root);
    }
    else
        delGreater(x, root->right);
}

void BST::delInterval(const int a, const int b, Node *&root)
{
    if (!root)
        return;
    if (root->data <= a)
        delInterval(a, b, root->right);
    else if (root->data >= b)
        delInterval(a, b, root->left);
    else
    {
        delGreater(a, root->left);
        delLess(b, root->right);
        del(root->data, root);
    }
}

bool BST::find(const int x, const Node *root)
{
    if (!root)
        return false;
    if (root->data == x)
        return true;
    return find(x, root->left) || find(x, root->right);
}

void BST::find(const int x)
{
    if (find(x, root))
        printf("Y\n");
    else
        printf("N\n");
}

void BST::find_ith(const int i, const Node *root)
{
    if (i < count)
        return;
    if (root->left)
        find_ith(i, root->left);
    ++count;
    if (count == i)
        num_ith = root->data;
    if (root->right)
        find_ith(i, root->right);
}

void BST::find_ith(const int i)
{
    if (!root)
    {
        printf("N\n");
        return;
    }
    count = 0;
    find_ith(i, root);
    if (count >= i)
        printf("%d\n", num_ith);
    else
        printf("N\n");
}

int main()
{
    BST BTree;
    int n, a, b;
    char command[25];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", command);
        scanf("%d", &a);
        switch (strlen(command))
        {
        case 4:
            BTree.find(a);
            break;
        case 8:
            BTree.find_ith(a);
            break;
        case 15:
            scanf("%d", &b);
            BTree.delInterval(a, b);
            break;
        case 16:
            BTree.delLess(a);
            break;
        case 19:
            BTree.delGreater(a);
            break;
        default:
            if (command[0] == 'i')
                BTree.insert(a);
            else
                BTree.del(a);
        }
        // BTree.traversal();
        // printf("\n");
    }
    return 0;
}