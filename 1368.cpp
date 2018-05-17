#include <iostream>
using namespace std;

class monkey
{
  private:
    struct node
    {
        node *next;
        int id;
        node(int i, node *p) : id(i), next(p) {}
    };

    int num;
    node *head, *prev;

  public:
    monkey() : num(0), head(NULL), prev(NULL) {}
    ~monkey()
    {
        node *tmp;
        for (int i = 0; i < num; ++i)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    void init(int n);
    void del(int k);
    void insert(int k, int w);
    int sum();
};

void monkey::init(int n)
{
    node *tmp;
    num = n;
    head = new node(1, NULL);
    for (int i = n; i > 1; --i)
    {
        tmp = head->next;
        head->next = new node(i, tmp);
        if (i == n)
            prev = head->next;
    }
    if (prev)
        prev->next = head;
}

void monkey::del(int k)
{
    node *tmp;
    k = (k - 1) % num + 1;
    for (int i = 1; i < k; ++i)
    {
        prev = prev->next;
    }
    tmp = prev->next;
    prev->next = prev->next->next;
    head = prev->next;
    delete tmp;
    --num;
}

void monkey::insert(int k, int w)
{
    node *tmp;
    if (num == 1)
    {
        tmp = head->next;
        head->next = new node(w, tmp);
        head->next->next = head;
        prev = head;
        head = head->next;
        ++num;
        return;
    }
    k = (k - 1) % num + 1;
    for (int i = 1; i < k; ++i)
    {
        head = head->next;
    }
    tmp = head->next;
    head->next = new node(w, tmp);
    prev = head;
    head = head->next;
    ++num;
}

int monkey::sum()
{
    int res = 0;
    node *p = head;
    for (int i = 0; i < num; ++i)
    {
        res += p->id;
        p = p->next;
    }
    return res;
}

int main()
{
    monkey a;
    int n, m, op, k, w;
    cin >> n >> m;
    a.init(n);
    for (int i = 0; i < m; ++i)
    {
        cin >> op;
        if (op)
        {
            cin >> k >> w;
            a.insert(k, w);
        }
        else
        {
            cin >> k;
            a.del(k);
        }
    }
    k = a.sum();
    cout << k << endl;
    return 0;
}