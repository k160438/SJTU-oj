#include <iostream>
using namespace std;

template <class elemType>
class seqList
{
  private:
    elemType *data;
    int currentLength;
    int maxSize;
    void doubleSpace();

  public:
    seqList(int initSize = 10) : currentLength(0), maxSize(initSize)
    {
        data = new elemType[maxSize];
    }
    ~seqList() { delete[] data; }
    int length() const;
    int search(const elemType &x) const;
    //if exists return index, otherwise return -1
    elemType visit(int i) const;
    void insert(int i, const elemType &x);
    void remove(int i);
    void clear();
    void traverse() const;
};

template <class elemType>
void seqList<elemType>::doubleSpace()
{
    elemType *tmp = data;
    data = new elemType[maxSize << 1];
    for (int i = 0; i < currentLength; ++i)
        data[i] = tmp[i];
    delete[] tmp;
    maxSize <<= 1;
}

template <class elemType>
int seqList<elemType>::length() const
{
    return currentLength;
}

template <class elemType>
int seqList<elemType>::search(const elemType &x) const
{
    for (int i = 0; i < currentLength; ++i)
        if (x == data[i])
            return i;
    return -1;
}

template <class elemType>
elemType seqList<elemType>::visit(int i) const
{
    return data[i];
}

template <class elemType>
void seqList<elemType>::insert(int i, const elemType &x)
{
    if (currentLength == maxSize)
        doubleSpace();
    for (int j = currentLength; j > i; --j)
        data[j] = data[j - 1];
    data[i] = x;
    ++currentLength;
}

template <class elemType>
void seqList<elemType>::remove(int i)
{
    for (int j = i; j < currentLength; ++j)
        data[j] = data[j + 1];
    --currentLength;
}

template <class elemType>
void seqList<elemType>::clear()
{
    currentLength = 0;
}

template <class elemType>
void seqList<elemType>::traverse() const
{
    for (int i = 0; i < currentLength; ++i)
        cout << data[i] << ' ';
}

int main()
{
    // seqList<int> s(3);
    // for (int i = 0; i < 7; ++i)
    //     s.insert(0,i);
    // cout<<s.length()<<endl;
    // s.traverse();
    // cout<<endl;
    // s.remove(3);
    // s.traverse();
    // cout<<endl;
    // s.insert(2,100);
    // s.traverse();
    // cout<<endl;
    // int i = s.visit(3);
    // cout<<i;
    // s.clear();
    // cout<<" "<<s.length();
    int a,b;
    cin>>a>>b;
    cout<<a+b<<endl;
    return 0;
}