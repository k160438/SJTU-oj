#include <iostream>
using namespace std;
#define maxsize 1000005

class mystack
{
    char *p;
    int *m;
    int large, medium, small, len;

  public:
    mystack() : large(0), medium(0), small(0), len(0)
    {
        p = new char[maxsize];
        m = new int[maxsize];
    }
    ~mystack()
    {
        delete[] p;
        delete[] m;
    }
    void push(char c);
    bool pop();
    char top();
    bool ismatch();
};

void mystack::push(char c)
{
    p[len] = c;
    switch (c)
    {
    case ')':
        --small;
        break;
    case '(':
        ++small;
        break;
    case ']':
        --medium;
        break;
    case '[':
        ++medium;
        break;
    case '}':
        --large;
        break;
    case '{':
        ++large;
        break;
    }

    ++len;
}

int main()
{

    return 0;
}