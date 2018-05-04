#include <cstdio>
#include <queue>
using namespace std;
#define maxsize 100005

int input[maxsize][3] = {0}, findroot[maxsize] = {0};

class BinaryTree
{
  private:
    struct Node
    {
        Node *ls, *rb;
        int data, id;
        Node(int i, int j) : ls(NULL), rb(NULL), data(i), id(j) {}
    };
    Node *root;
    void preorderTraversal(Node *root) const;
    void postorderTraversal(Node *root) const;

  public:
    void create(int root);
    void levelTraversal() const;
    void preorderTraversal() const;
    void postorderTraversal() const;
};

void BinaryTree::create(int n)
{
    queue<Node *> q;
    Node *tmp;
    int l, r;
    root = new Node(input[n][2], n);
    q.push(root);
    while (q.size())
    {
        tmp = q.front();
        q.pop();
        l = input[tmp->id][0];
        r = input[tmp->id][1];
        if (l)
        {
            tmp->ls = new Node(input[l][2], l);
            q.push(tmp->ls);
        }
        if (r)
        {
            tmp->rb = new Node(input[r][2], r);
            q.push(tmp->rb);
        }
    }
}

void BinaryTree::levelTraversal() const
{
    Node *tmp;
    queue<Node *> q;
    q.push(root);
    while (q.size())
    {
        tmp = q.front();
        q.pop();
        while (tmp)
        {
            printf("%d ", tmp->data);
            if (tmp->ls)
                q.push(tmp->ls);
            tmp = tmp->rb;
        }
    }
}

void BinaryTree::preorderTraversal() const
{
    preorderTraversal(root);
}

void BinaryTree::postorderTraversal() const
{
    postorderTraversal(root);
}

void BinaryTree::preorderTraversal(Node *root) const
{
    printf("%d ", root->data);
    if (root->ls)
        preorderTraversal(root->ls);
    if (root->rb)
        preorderTraversal(root->rb);
}

void BinaryTree::postorderTraversal(Node *root) const
{
    Node * tmp = root->ls;
    while(tmp)
    {
        postorderTraversal(tmp);
        tmp = tmp->rb;
    }
    printf("%d ", root->data);
}

int main()
{
    int n, root;
    BinaryTree myTree;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d %d %d", &input[i][0], &input[i][1], &input[i][2]);
        findroot[input[i][0]] = 1;
        findroot[input[i][1]] = 1;
    }
    for (int i = 1; i <= n; ++i)
        if (!findroot[i])
        {
            root = i;
            break;
        }
    myTree.create(root);
    myTree.preorderTraversal();
    printf("\n");
    myTree.postorderTraversal();
    printf("\n");
    myTree.levelTraversal();
    return 0;
}