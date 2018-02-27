#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, a, b;
    double price;
    scanf("%d %d", &n, &m);
    scanf("%d %d", &a, &b);
    price = double(a) / b;
    for (int i = 1; i < n; ++i)
    {
        scanf("%d %d", &a, &b);
        price = min(price, double(a) / b);
    }
    printf("%.9lf", m * price);
    return 0;
}