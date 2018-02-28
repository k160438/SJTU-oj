#include <iostream>
#include <string.h>
using namespace std;

template <class T>
struct LinkRec
{
    T data;
    LinkRec *next;
};

template <class T>
class LinkTab;

template <class T>
ostream &operator<<(ostream &os, const LinkTab<T> &obj);
template <class T>
void run(LinkTab<T> &a, LinkTab<T> &b);
template <class T>
LinkTab<T> operator+(const LinkTab<T> &a, const LinkTab<T> &b);

template <class T>
class LinkTab
{
    friend ostream &operator<<<>(ostream &os, const LinkTab<T> &obj);
    friend void run<>(LinkTab<T> &a, LinkTab<T> &b);
    friend LinkTab<T> operator+<>(const LinkTab<T> &a, const LinkTab<T> &b);

  private:
    LinkRec<T> *head;

  public:
    LinkTab() : head(NULL) {}
    ~LinkTab()
    {
        LinkRec<T> *tmp;
        while (head)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};

template <class T>
ostream &operator<<(ostream &os, const LinkTab<T> &obj)
{
    LinkRec<T> *p;
    for (p = obj.head; p; p = p->next)
        os << p->data << ' ';
    return os;
}

template <class T>
LinkTab<T> operator+(const LinkTab<T> &a, const LinkTab<T> &b)
{
    LinkTab<T> res;
    LinkRec<T> *p, *q;
    res.head = new LinkRec<T>;
    res.head->data = a.head->data;
    res.head->next = NULL;
    p = res.head;
    q = a.head->next;
    while (q)
    {
        p->next = new LinkRec<T>;
        p->next->data = q->data;
        p->next->next = NULL;
        p = p->next;
        q = q->next;
    }
    q = b.head;
    while (q)
    {
        p->next = new LinkRec<T>;
        p->next->data = q->data;
        p->next->next = NULL;
        p = p->next;
        q = q->next;
    }
    return res;
}

template <class T>
void run(LinkTab<T> &a, LinkTab<T> &b)
{
    int n, m;
    cin >> m >> n;
    LinkRec<T> *tmp;
    T s;
    a.head = new LinkRec<T>;
    cin >> s;
    a.head->data = s;
    a.head->next = NULL;
    tmp = a.head;
    for (int i = 0; i < m - 1; ++i)
    {
        cin >> s;
        tmp->next = new LinkRec<T>;
        tmp->next->data = s;
        tmp->next->next = NULL;
        tmp = tmp->next;
    }
    b.head = new LinkRec<T>;
    cin >> s;
    b.head->data = s;
    b.head->next = NULL;
    tmp = b.head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> s;
        tmp->next = new LinkRec<T>;
        tmp->next->data = s;
        tmp->next->next = NULL;
        tmp = tmp->next;
    }
    cout << a + b << endl;
}

int main()
{
    char ss[10];
    cin >> ss;
    if (strlen(ss) == 3)
    {
        LinkTab<int> a, b;
        run(a, b);
    }
    else if (strlen(ss) == 4)
    {
        LinkTab<char> a, b;
        run(a, b);
    }
    else
    {
        LinkTab<double> a, b;
        run(a, b);
    }

    return 0;
}