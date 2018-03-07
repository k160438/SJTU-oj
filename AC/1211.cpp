#include <cstdio>
#include <queue>
using namespace std;
#define maxsize 100005

int nums[maxsize][2] = {0}, findroot[maxsize] = {0};

class BinaryTree
{
  private:
    struct Node
    {
        Node *left, *right;
        int data;
        Node() : left(NULL), right(NULL) {}
        Node(int i, Node *l, Node *r) : data(i), left(l), right(r) {}
        ~Node() {}
    };
    Node *root;

  public:
    BinaryTree() : root(NULL) {}
    ~BinaryTree() { clear(root); }
    void clear(Node *root)
    {
        if (root->left)
            clear(root->left);
        if (root->right)
            clear(root->right);
        delete root;
    }
    void create(int n)
    {
        queue<Node *> q;
        Node *tmp;
        root = new Node(n, NULL, NULL);
        q.push(root);
        while (q.size())
        {
            tmp = q.front();
            q.pop();
            if (nums[tmp->data][0])
            {
                tmp->left = new Node(nums[tmp->data][0], NULL, NULL);
                q.push(tmp->left);
            }
            if (nums[tmp->data][1])
            {
                tmp->right = new Node(nums[tmp->data][1], NULL, NULL);
                q.push(tmp->right);
            }
        }
    }
    bool isCBT()
    {
        bool flag = false;
        queue<Node *> q;
        Node *tmp;
        q.push(root);
        while (q.size())
        {
            tmp = q.front();
            q.pop();
            if (flag && (tmp->left || tmp->right))
                return false;
            if (tmp->left && tmp->right)
            {
                q.push(tmp->left);
                q.push(tmp->right);
            }
            else
            {
                flag = true;
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    int N, root, height = 0;
    BinaryTree tree;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d %d", &nums[i][0], &nums[i][1]);
        findroot[nums[i][0]] = 1;
        findroot[nums[i][1]] = 1;
    }
    for (int i = 1; i <= N; ++i)
        if (!findroot[i])
        {
            root = i;
            break;
        }

    tree.create(root);
    if (tree.isCBT())
        printf("%c", 'Y');
    else
        printf("%c", 'N');
    return 0;
}
