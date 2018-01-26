#include <iostream>
using namespace std;
#define maxsize 310

class BigInt
{
    friend istream &operator>>(istream &is, BigInt &obj);
    friend ostream &operator<<(ostream &os, const BigInt &obj);
    friend bool operator>=(const BigInt &a, const BigInt &b);
    friend BigInt operator/(const BigInt &a, const BigInt &b);

  private:
    int *nums;
    int len;

  public:
    BigInt(int l = 0, int *source = NULL) : len(l)
    {
        nums = new int[maxsize];
        for (int i = 0; i < l; ++i)
            nums[i] = source[i];
    }
    ~BigInt()
    {
        delete[] nums;
    }
    BigInt &operator-=(const BigInt &b);
};

bool operator>=(const BigInt &a, const BigInt &b)
{
    if (a.len > b.len)
        return true;
    else if (a.len < b.len)
        return false;
    else
    {
        for (int i = 0; i < a.len; ++i)
        {
            if (a.nums[i] > b.nums[i])
                return true;
            if (a.nums[i] < b.nums[i])
                return false;
        }
        return true;
    }
}

BigInt &BigInt::operator-=(const BigInt &b)
{
    int i, lena = len, lenb = b.len;
    for (i = 1; i <= lenb; ++i)
    {
        if (nums[lena - i] >= b.nums[lenb - i])
            nums[lena - i] -= b.nums[lenb - i];
        else
        {
            nums[lena - i - 1] -= 1;
            nums[lena - i] -= b.nums[lenb - i] - 10;
        }
    }
    i = 0;
    while (nums[i] == 0)
    {
        ++i;
    }
    if (i)
    {
        len -= i;
        for (int j = 0; j < len; ++j)
            nums[j] = nums[j + i];
    }
    return *this;
}

BigInt operator/(const BigInt &a, const BigInt &b)
{
    BigInt res;
    if (!(a >= b))
    {
        res.nums[res.len++] = 0;
    }
    else
    {
        BigInt tmp(b.len, a.nums);
        for (int i = 0; i < a.len - b.len + 1; ++i)
        {
            res.nums[res.len++] = 0;
            while (tmp >= b)
            {
                res.nums[res.len - 1] += 1;
                tmp -= b;
            }
            tmp.nums[tmp.len++] = a.nums[b.len + i];
        }
        int i = 0;
        while (res.nums[i] == 0)
            ++i;
        if (i)
        {
            res.len -= i;
            for (int j = 0; j < res.len; ++j)
                res.nums[j] = res.nums[j + i];
        }
    }
    return res;
}

istream &operator>>(istream &is, BigInt &obj)
{
    char tmp;
    while ((tmp = is.get()) != '\n')
    {
        obj.nums[(obj.len)++] = tmp - '0';
    }
    return is;
}

ostream &operator<<(ostream &os, const BigInt &obj)
{
    for (int i = 0; i < obj.len; ++i)
        os << obj.nums[i];
    if (!obj.len)
        os << 0;
    return os;
}

int main()
{
    BigInt a, b;
    cin >> a;
    cin >> b;
    // cout << a << endl;
    // cout << b << endl;
    cout << a/b << endl;
    // cout << a << endl;
    return 0;
}