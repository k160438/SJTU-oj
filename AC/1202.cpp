#include <iostream>
using namespace std;

class BigInt
{
    friend BigInt operator+(const BigInt &a, const BigInt &b);
    friend ostream &operator<<(ostream &os, const BigInt &obj);
    friend istream &operator>>(istream &is, BigInt &obj);

  private:
    struct LinkRec
    {
        int data;
        LinkRec *next, *prev;
    };
    LinkRec *head, *tail;

  public:
    BigInt() : head(NULL), tail(NULL) {}
    ~BigInt()
    {
        LinkRec *tmp;
        while (head)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    BigInt &operator=(const BigInt &obj);
};

BigInt &BigInt::operator=(const BigInt &obj)
{
    if (this == &obj)
        return *this;
    BigInt::LinkRec *p, *q;
    head = new BigInt::LinkRec;
    head->prev = NULL;
    head->data = obj.head->data;
    for (p = head, q = obj.head->next; q; p = p->next, q = q->next)
    {
        p->next = new BigInt::LinkRec;
        p->next->data = q->data;
        p->next->prev = p;
    }
    p->next = NULL;
    tail = p;
    return *this;
}

BigInt operator+(const BigInt &a, const BigInt &b)
{
    BigInt res;
    BigInt::LinkRec *p, *q;
    int jinwei = 0;
    res.tail = new BigInt::LinkRec;
    res.head = res.tail;
    jinwei = (a.tail->data + b.tail->data) / 10;
    res.tail->data = (a.tail->data + b.tail->data) % 10;
    res.tail->next = NULL;
    res.tail->prev = NULL;
    for (p = a.tail->prev, q = b.tail->prev; p && q; p = p->prev, q = q->prev)
    {
        res.head->prev = new BigInt::LinkRec;
        res.head->prev->next = res.head;
        res.head = res.head->prev;
        res.head->prev = NULL;
        res.head->data = (p->data + q->data + jinwei) % 10;
        jinwei = (p->data + q->data + jinwei) / 10;
    }
    if (q)
        p = q;
    while (p)
    {
        res.head->prev = new BigInt::LinkRec;
        res.head->prev->next = res.head;
        res.head = res.head->prev;
        res.head->prev = NULL;
        res.head->data = (p->data + jinwei) % 10;
        jinwei = (p->data + jinwei) / 10;
        p = p->prev;
    }
    if (jinwei)
    {
        res.head->prev = new BigInt::LinkRec;
        res.head->prev->next = res.head;
        res.head = res.head->prev;
        res.head->prev = NULL;
        res.head->data = jinwei;
    }
    return res;
}

ostream &operator<<(ostream &os, const BigInt &obj)
{
    BigInt::LinkRec *tmp = obj.head;
    for (; tmp != NULL; tmp = tmp->next)
        os << tmp->data;
    return os;
}
istream &operator>>(istream &is, BigInt &obj)
{
    char tmp;
    tmp = is.get();
    if (tmp != '\n')
    {
        obj.tail = new BigInt::LinkRec;
        obj.head = obj.tail;
        obj.tail->data = tmp - '0';
        obj.tail->next = NULL;
        obj.tail->prev = NULL;
    }
    while ((tmp = is.get()) != '\n')
    {
        obj.tail->next = new BigInt::LinkRec;
        obj.tail->next->prev = obj.tail;
        obj.tail = obj.tail->next;
        obj.tail->data = tmp - '0';
        obj.tail->next = NULL;
    }
    return is;
}

int main()
{
    BigInt a, b, res;
    cin >> a >> b;
    res = a + b;
    cout << res << endl;
    return 0;
}