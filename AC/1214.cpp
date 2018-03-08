#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
#define maxsize 100005

int nums[maxsize][3] = {0}, findroot[maxsize] = {0};

class BinaryTree
{
  private:
    struct Node
    {
        Node *next, *right;
        int id, data;
        Node() : next(NULL), right(NULL) {}
        Node(int i, int j, Node *l, Node *r) : id(i), data(j), next(l), right(r) {}
        ~Node() {}
    };
    Node *root;

  public:
    BinaryTree() : root(NULL) {}
    ~BinaryTree() { clear(root); }
    void clear(Node *root)
    {
        if (root->next)
            clear(root->next);
        if (root->right)
            clear(root->right);
        delete root;
    }

    Node *getRoot() const
    {
        return root;
    }
    void create(int n)
    {
        queue<Node *> q;
        Node *tmp;
        root = new Node(n, nums[n][2], NULL, NULL);
        q.push(root);
        while (q.size())
        {
            tmp = q.front();
            q.pop();
            if (nums[tmp->id][0])
            {
                tmp->next = new Node(nums[tmp->id][0], nums[nums[tmp->id][0]][2], NULL, NULL);
                q.push(tmp->next);
            }
            if (nums[tmp->id][1])
            {
                tmp->right = new Node(nums[tmp->id][1], nums[nums[tmp->id][1]][2], NULL, NULL);
                q.push(tmp->right);
            }
        }
    }

    void levelTraversal()
    {
        queue<Node *> q;
        Node *tmp;
        q.push(root);
        // while (q.size())
        // {
        //     tmp = q.front();
        //     q.pop();
        //     printf("%d ", tmp->data);
        //     if (tmp->left)
        //         q.push(tmp->left);
        //     if (tmp->right)
        //         q.push(tmp->right);
        // }
        while (q.size())
        {
            tmp = q.front();
            q.pop();
            for (; tmp != NULL; tmp = tmp->right)
            {
                printf("%d ", tmp->data);
                if (tmp->next)
                    q.push(tmp->next);
            }
        }
    }

    void preTraversal(const Node *root)
    {
        // stack<Node *> q;
        // Node *tmp;
        // q.push(root);
        // while (q.size())
        // {
        //     tmp = q.top();
        //     q.pop();
        //     printf("%d ", tmp->data);
        //     if (tmp->right)
        //         q.push(tmp->right);
        //     if (tmp->left)
        //         q.push(tmp->left);
        // }
        printf("%d ", root->data);
        if (root->next)
            preTraversal(root->next);
        if (root->right)
            preTraversal(root->right);
    }

    void postTraversal(const Node *root)
    {
        // stack<Node *> q;
        // Node *tmp;
        // int i = 0;
        // q.push(root);
        // while (q.size())
        // {
        //     tmp = q.top();
        //     q.pop();
        //     findroot[++i] = tmp->data;
        //     if (tmp->left)
        //         q.push(tmp->left);
        //     if (tmp->right)
        //         q.push(tmp->right);
        // }
        // for (; i > 0; --i)
        //     printf("%d ", findroot[i]);
        if (root->next)
            postTraversal(root->next);
        printf("%d ", root->data);
        if (root->right)
            postTraversal(root->right);
    }
};

int main()
{
    int N, root, height = 0;
    BinaryTree tree;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d %d %d", &nums[i][0], &nums[i][1], &nums[i][2]);
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
    tree.preTraversal(tree.getRoot());
    printf("\n");
    tree.postTraversal(tree.getRoot());
    printf("\n");
    tree.levelTraversal();

    return 0;
}
