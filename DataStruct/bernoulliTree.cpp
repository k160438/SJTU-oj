#include <iostream>
using namespace std;

class BernoulliTree
{
  private:
    struct Node
    {
        Node *son, *sibling;
        int data, height; //代表以此结点为根节点的bernoulli树的高度
        Node(int a) : son(NULL), sibling(NULL), height(0), data(a) {}
    };
    Node *forest[17];
    void merge(Node *p);

  public:
    BernoulliTree()
    {
        for (int i = 0; i < 17; ++i)
            forest[i] = NULL;
    }
    ~BernoulliTree()
    {
        for (int i = 0; i < 17; ++i)
            if (forest[i])
                delete forest[i];
    }
    void insert(int x);
    int min() const;
    void del();
};

void BernoulliTree::merge(Node *p)
{
    int h = p->height;
    Node *Min, *tmp, *q;
    if (forest[h])
    {
        if (p->data < forest[h]->data)
        {
            Min = p;
            q = forest[h];
        }
        else
        {
            Min = forest[h];
            q = p;
        }
        Min->height += 1;
        forest[h] = NULL;
        if (!Min->son)
            Min->son = q;
        else
        {
            tmp = Min->son;
            while (tmp->sibling)
                tmp = tmp->sibling;
            tmp->sibling = q;
        }
        merge(Min);
    }
    else
        forest[h] = p;
}

void BernoulliTree::insert(int x)
{
    Node *p;
    p = new Node(x);
    merge(p);
}

int BernoulliTree::min() const
{
    int Min = 2147483647;
    for (int i = 0; i < 17; ++i)
        if (forest[i] && forest[i]->data < Min)
            Min = forest[i]->data;
    return Min;
}

void BernoulliTree::del()
{
    int Min = 2147483647;
    Node *index, *tmp;
    for (int i = 0; i < 17; ++i)
        if (forest[i] && forest[i]->data < Min)
        {
            index = forest[i];
            Min = index->data;
        }
    forest[index->height] = NULL;
    tmp = index;
    index = index->son;
    delete tmp;
    while (index)
    {
        tmp = index->sibling;
        index->sibling = NULL;
        merge(index);
        index = tmp;
    }
}

int main()
{
    int M, k;
    char command[10];
    BernoulliTree pt;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> command;
        switch (command[0])
        {
        case 'i':
            cin >> k;
            pt.insert(k);
            break;
        case 'd':
            pt.del();
            break;
        default:
            cout << pt.min() << '\n';
        }
    }
    return 0;
}