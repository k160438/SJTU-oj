#include <cstdio>
#include <stack>
#include <map>
using namespace std;

struct Node
{
    int id;
    Node *parent, *left, *right;
    Node(int i, Node *p, Node *l, Node *r) : id(i), parent(p), left(l), right(r) {}
};

map<int, Node *> index;

void op1()
{
    Node *tmp;
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (b == c || index.find(a) == index.end() || index.find(b) != index.end() || index.find(c) != index.end())
    {
        printf("Error!\n");
        return;
    }
    tmp = index[a];
    if (tmp->left || tmp->right)
    {
        printf("Error!\n");
        return;
    }
    printf("Ok!\n");
    tmp->left = new Node(b, tmp, NULL, NULL);
    index[b] = tmp->left;
    tmp->right = new Node(c, tmp, NULL, NULL);
    index[c] = tmp->right;
}

void op2()
{
    int a;
    scanf("%d", &a);
    if (index.find(a) == index.end())
        printf("Error!\n");
    else
    {
        Node *tmp;
        tmp = index[a];
        if (tmp->parent)
            printf("%d ", tmp->parent->id);
        else
            printf("0 ");
        if (tmp->left)
            printf("%d ", tmp->left->id);
        else
            printf("0 ");
        if (tmp->right)
            printf("%d\n", tmp->right->id);
        else
            printf("0\n");
    }
}

void op3()
{
    int a;
    Node *p, *q;
    scanf("%d", &a);
    if (a == 1 || index.find(a) == index.end())
        printf("Error!\n");
    else
    {
        p = index[a]->parent;
        q = p->right;
        if (q->id != a)
            printf("%d\n", q->id);
        else
            printf("%d\n", p->left->id);
        p->right = p->left;
        p->left = q;
    }
}

void preorderTra(Node *root)
{
    stack<Node *> s;
    Node *tmp;
    s.push(root);
    while (s.size())
    {
        tmp = s.top();
        s.pop();
        printf("%d ", tmp->id);
        if (tmp->right)
            s.push(tmp->right);
        if (tmp->left)
            s.push(tmp->left);
    }
}

int main()
{
    int m, op;
    Node *root;
    root = new Node(1, NULL, NULL, NULL);
    index[1] = root;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            op1();
            break;
        case 2:
            op2();
            break;
        default:
            op3();
        }
    }
    preorderTra(root);
    return 0;
}