#include <iostream>
#include <algorithm>
using namespace std;

class Set
{
    int num;
    int *data;

  public:
    Set() : num(0)
    {
        data = new int[10005];
    }
    ~Set()
    {
        delete[] data;
    }

    void setData(int n, const int array[]);
    void print();
    void add(const Set &obj);
    void subtract(Set &obj);
    void multiply(Set &obj);
    bool binarySearch(int x);
};

void Set::setData(int n, const int array[])
{
    num = n;
    for (int i = 0; i < n; ++i)
        data[i] = array[i];
    if (n > 1)
        sort(data, data + n);
}

void Set::print()
{
    for (int i = 0; i < num; ++i)
        cout << data[i] << ' ';
    cout << '\n';
}

bool Set::binarySearch(int x)
{
    int l = 0, r = num - 1, mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (data[mid] == x)
            return true;
        if (data[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}

void Set::add(const Set &obj)
{
    int *tmp, i = 0, j = 0, n = -1;
    tmp = new int[num];
    for (int k = 0; k < num; ++k)
        tmp[k] = data[k];
    while (i < num || j < obj.num)
    {
        if (j >= obj.num || (i < num && tmp[i] < obj.data[j]))
        {
            if (n < 0 || tmp[i] > data[n])
                data[++n] = tmp[i];
            ++i;
        }
        else
        {
            if (n < 0 || obj.data[j] > data[n])
                data[++n] = obj.data[j];
            ++j;
        }
    }
    num = n + 1;
    print();
}

void Set::subtract(Set &obj)
{
    int n = 0;
    for (int i = 0; i < num; ++i)
        if (!obj.binarySearch(data[i]))
            data[n++] = data[i];
    num = n;
    print();
}

void Set::multiply(Set &obj)
{
    int n = 0;
    for (int i = 0; i < num; ++i)
        if (obj.binarySearch(data[i]))
            data[n++] = data[i];
    num = n;
    print();
}

int main()
{
    int n, m;
    int array[105];
    char c;
    Set myset, b;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> c >> m;
        for (int j = 0; j < m; ++j)
            cin >> array[j];
        b.setData(m, array);
        switch (c)
        {
        case '+':
            myset.add(b);
            break;
        case '-':
            myset.subtract(b);
            break;
        default:
            myset.multiply(b);
        }
    }
    return 0;
}