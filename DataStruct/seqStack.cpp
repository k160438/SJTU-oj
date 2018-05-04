#include<cstdio>
using namespace std;

template<class elemType>
class seqStack
{
private:
    elemType *elem;
    int topIndex;
    int maxsize;
    void doublesize();
public:
    seqStack(int size);
    seqStack();
    ~seqStack();
    bool isEmpty()const;
    elemType top()const;
    elemType pop();
    void push(const elemType &a);
};

template<class elemType>
seqStack<elemType>::seqStack(int size):maxsize(size),topIndex(-1)
{
    elem = new elemType[maxsize];
}

template<class elemType>
seqStack<elemType>::seqStack():maxsize(10),topIndex(-1)
{
    elem = new elemType[maxsize];
}

template<class elemType>
seqStack<elemType>::~seqStack()
{
    delete []elem;
}

template<class elemType>
void seqStack<elemType>::doublesize()
{
    elemType *tmp = elem;
    elem = new elemType[maxsize<<1];
    for(int i=0;i<maxsize;++i)
        elem[i] = tmp[i];
    delete []tmp;
    maxsize<<=1;
}

template<class elemType>
bool seqStack<elemType>::isEmpty() const
{
    return topIndex<0;
}

template<class elemType>
elemType seqStack<elemType>::top()const
{
    return elem[topIndex];
}

template<class elemType>
elemType seqStack<elemType>::pop()
{
    return elem[topIndex--];
}

template<class elemType>
void seqStack<elemType>::push(const elemType &a)
{
    ++topIndex;
    if(topIndex==maxsize)
        doublesize();
    elem[topIndex] = a;
}

int main()
{
    // int tmp;
    // seqStack<int> s;
    // for(int i=0;i<15;++i)
    // s.push(i);
    // printf("%d\n", s.top());
    // while(!s.isEmpty())
    // {
    //     tmp = s.pop();
    //     printf("%d ", tmp);
    // }

    int a,b;
    scanf("%d %d", &a, &b);
    printf("%d", a+b);
    return 0;
}