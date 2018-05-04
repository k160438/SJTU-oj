#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

template <class Type>
class BinaryTree
{
  private:
    struct Node
    {
        Node *left, *right; // 结点的左、右儿子的地址
        Type data;          // 结点的数据信息
        Node() : left(NULL), right(NULL) {}
        Node(Type item, Node *L = NULL, Node *R = NULL) : data(item), left(L), right(R) {}
        ~Node() {}
    };

    Node *root; // 二叉树的根结点。
  public:
    BinaryTree() : root(NULL) {} // 构造空二叉树
    BinaryTree(const Type &value)
    {
        root = new Node(value);
    }
    BinaryTree(Node *p)
    {
        root = p;
    }
    ~BinaryTree() { clear(); }
    Type getRoot() const
    {
        return root->data;
    }
    Type getLeft() const
    {
        return root->left->data;
    }
    Type getRight() const
    {
        return root->right->data;
    }
    void makeTree(const Type &x, BinaryTree &lt,
                  BinaryTree &rt)
    {
        root = new Node(x, lt.root, rt.root);
        lt.root = NULL;
        rt.root = NULL;
    }
    void delLeft()
    {
        BinaryTree tmp = root->left;
        root->left = NULL;
        tmp.clear();
    }
    void delRight()
    {
        BinaryTree tmp = root->right;
        root->right = NULL;
        tmp.clear();
    }
    bool isEmpty() const
    {
        return root == NULL;
    }
    void clear()
    {
        if (root != NULL)
            clear(root);
        root = NULL;
    }
    int size() const { return size(root); }
    int height() const { return height(root); }
    void preOrder() const
    {
        if (root)
            preOrder(root);
    }
    void postOrder() const
    {
        if (root)
            postOrder(root);
    }
    void inOrder() const
    {
        if (root)
            inOrder(root);
    }
    void createTree(Type flag);
    void postOrder_stack() const;

  private:
    void clear(Node *t);
    int height(Node *t) const;
    int size(Node *t) const;
    void preOrder(Node *t) const;
    void postOrder(Node *t) const;
    void inOrder(Node *t) const;
};

template <class Type>
void BinaryTree<Type>::clear(Node *t)
{
    if (t->left)
        clear(t->left);
    if (t->right)
        clear(t->right);
    delete t;
}

template <class Type>
int BinaryTree<Type>::height(Node *t) const
{
    if (!t)
        return 0;
    return 1 + max(height(t->left), height(r->right));
}

template <class Type>
int BinaryTree<Type>::size(Node *t) const
{
    if (!t)
        return 0;
    return 1 + size(t->left) + size(t->right);
}

template <class Type>
void BinaryTree<Type>::preOrder(Node *t) const
{
    cout << t->data << ' ';
    if (t->left)
        preOrder(t -> left);
    if (t->right)
        preOrder(t->right);
}

template <class Type>
void BinaryTree<Type>::postOrder(Node *t) const
{
    if (t->left)
        postOrder(t -> left);
    if (t->right)
        postOrder(t->right);
    cout << t->data << ' ';
}

template <class Type>
void BinaryTree<Type>::inOrder(Node *t) const
{
    if (t->left)
        inOrder(t -> left);
    cout << t->data << ' ';
    if (t->right)
        inOrder(t->right);
}

// template <class Type>
// void BinaryTree<Type>::postOrder_stack() const
// {
//     Node *tmp;
//     int num;
//     stack<Node *> sn;
//     stack<int> si;
//     if (root)
//     {
//         sn.push(root);
//         si.push(0);
//     }
//     while (sn.size())
//     {
//         tmp = sn.top();
//         sn.pop();
//         num = si.top() + 1;
//         si.pop();
//         if (num == 1)
//         {
//             sn.push(tmp);
//             si.push(num);
//             if (tmp->left)
//             {
//                 sn.push(tmp->left);
//                 si.push(0);
//             }
//         }
//         else if (num == 2)
//         {
//             sn.push(tmp);
//             si.push(num);
//             if (tmp->right)
//             {
//                 sn.push(tmp->right);
//                 si.push(0);
//             }
//         }
//         else
//             cout << tmp->data << ' ';
//     }
// }

template<class elemType> 
void BinaryTree<elemType>::postOrder_stack() const
{
    
}