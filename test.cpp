#include <iostream>
#include "test.h"
using namespace std;
int a = 2;
int main()
{
    int b = 4;
    b = add(a, b); 
    cout << b << endl;
    cin >> b;
    cout << b << endl;
    return 0;
}