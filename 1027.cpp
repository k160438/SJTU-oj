#include <cstdio>
#include <algorithm>
using namespace std;
#define maxsize 1005

struct Plane
{
    int t, u, g, id;
};

bool comp(const Plane &a, const Plane &b)
{
    return a.t < b.t;
}

Plane p[maxsize];

int main()
{
    int n, MAX, s, bTime = 0;
    scanf("%d %d %d", &n, &MAX, &s);
    for (int i = 0; i < n; ++i)
    {
        p[i].id = i;
        scanf("%d %d %d", &p[i].t, &p[i].u, &p[i].g);
    }
    sort(p, p+n, comp);
    
    return 0;
}