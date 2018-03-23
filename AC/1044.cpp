#include <cstdio>
#include <limits.h>
#include <cstring>
#include <queue>
using namespace std;

struct Unit
{
    char name[25];
    int food, wood, rank;
};

Unit types[11];

int main()
{
    int k, n, food = 0, wood = 0, farmers = 0;
    int r, num, id = -1, a, b;
    char s[10];
    queue<int> food_unit, wood_unit;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
        scanf("%s %d %d %d", &types[i].name, &types[i].food, &types[i].wood, &types[i].rank);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s %d", &s, &num);
        if (s[0] == 'f')
        {
            food += num + farmers;
            food_unit.push(num + farmers);
        }
        else
        {
            wood += num + farmers;
            wood_unit.push(num + farmers);
        }
        id = -1;
        r = INT_MIN;
        for (int j = 0; j < k; ++j)
            if (types[j].food <= food && types[j].wood <= wood && types[j].rank > r)
            {
                r = types[j].rank;
                id = j;
            }
        if (id >= 0)
        {
            printf("#%d: a %s was created.\n", i, types[id].name);
            if (strcmp(types[id].name, "farmer") == 0)
                ++farmers;
            a = b = 0;
            while (a < types[id].food)
            {
                a += food_unit.front();
                food_unit.pop();
            }
            food -= a;
            while (b < types[id].wood)
            {
                b += wood_unit.front();
                wood_unit.pop();
            }
            wood -= b;
        }
    }
    printf("food: %d, wood: %d", food, wood);
    return 0;
}