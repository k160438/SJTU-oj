#include <iostream>
#include <iomanip>
using namespace std;

class MyComplex
{
    friend istream &operator>>(istream &is, const MyComplex &c);
    friend ostream &operator<<(ostream &os, const MyComplex &c);
    friend MyComplex operator+(const MyComplex &a, const MyComplex &b);
    friend MyComplex operator-(const MyComplex &a, const MyComplex &b);
    friend MyComplex operator*(const MyComplex &a, const MyComplex &b);
    friend MyComplex operator/(const MyComplex &a, const MyComplex &b);

  private:
    double x, y;

  public:
    /* Implementation of MyComplex */
    MyComplex(double a = 0, double b = 0) : x(a), y(b) {}

    void set(int a, int b)
    {
        x = a;
        y = b;
    }

    MyComplex &operator+=(const MyComplex &b);
    MyComplex &operator-=(const MyComplex &b);
    MyComplex &operator*=(const MyComplex &b);
    MyComplex &operator/=(const MyComplex &b);
};

MyComplex operator+(const MyComplex &a, const MyComplex &b)
{
    return MyComplex(a.x + b.x, a.y + b.y);
}

MyComplex operator-(const MyComplex &a, const MyComplex &b)
{
    return MyComplex(a.x - b.x, a.y - b.y);
}

MyComplex operator*(const MyComplex &a, const MyComplex &b)
{
    return MyComplex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

MyComplex operator/(const MyComplex &a, const MyComplex &b)
{
    double tmp = b.x * b.x + b.y * b.y;
    return MyComplex((a.x * b.x + a.y * b.y) / tmp, (a.y * b.x - a.x * b.y) / tmp);
}

ostream &operator<<(ostream &os, const MyComplex &c)
{
    os << fixed << setprecision(2) << c.x << ' ' << fixed << setprecision(2) << c.y;
    return os;
}

istream &operator>>(istream &is, MyComplex &c)
{
    int x, y;
    is >> x >> y;
    c.set(x, y);
    return is;
}

MyComplex &MyComplex::operator+=(const MyComplex &b)
{
    x += b.x;
    y += b.y;
    return *this;
}

MyComplex &MyComplex::operator-=(const MyComplex &b)
{
    x -= b.x;
    y -= b.y;
    return *this;
}

MyComplex &MyComplex::operator*=(const MyComplex &b)
{
    double tmp;
    tmp = x * b.x - y * b.y;
    y = x * b.y + y * b.x;
    x = tmp;
    return *this;
}

MyComplex &MyComplex::operator/=(const MyComplex &b)
{
    double tmp;
    tmp = (x * b.x + y * b.y) / (b.x * b.x + b.y * b.y);
    y = (y * b.x - x * b.y) / (b.x * b.x + b.y * b.y);
    x = tmp;
    return *this;
}

int main()
{
    MyComplex z1;
    MyComplex z2;

    cin >> z1 >> z2;

    cout << z1 + z2 << endl;
    cout << z1 - z2 << endl;
    cout << z1 * z2 << endl;
    cout << z1 / z2 << endl;
    cout << (z1 += z2) << endl;
    cout << (z1 -= z2) << endl;
    cout << (z1 *= z2) << endl;
    cout << (z1 /= z2) << endl;

    return 0;
}