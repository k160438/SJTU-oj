#include <cstdio>
#include <queue>
using namespace std;
#define maxsize 100005

struct Node
{
    int numOfNodes, left, right, numOfRed, red;
};

Node nodes[maxsize] = {{0}};
queue<int> q;
int levelTra[maxsize] = {0}, findRoot[maxsize] = {0};

void InOrderOfLevelTraversal(int root)
{
    int tmp, count = 0;
    q.push(root);
    while (q.size())
    {
        tmp = q.front();
        q.pop();
        levelTra[++count] = tmp;
        if (nodes[tmp].left)
            q.push(nodes[tmp].left);
        if (nodes[tmp].right)
            q.push(nodes[tmp].right);
    }
}

void brushToRed(int root, int x)
{
    if (nodes[nodes[root].left].numOfNodes == x - 1)
    {
        if (!nodes[root].red)
        {
            nodes[root].red = 1;
            nodes[root].numOfRed += 1;
        }
    }
    else
    {
        if (nodes[nodes[root].left].numOfNodes > x - 1)
            brushToRed(nodes[root].left, x);
        else
            brushToRed(nodes[root].right, x - 1 - nodes[nodes[root].left].numOfNodes);
    }
}

int main()
{
    int N, P, Q, x, l, r, root;
    scanf("%d %d %d", &N, &P, &Q);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d %d %d", &x, &l, &r);
        findRoot[l] = 1;
        findRoot[r] = 1;
        nodes[x].left = l;
        nodes[x].right = r;
        nodes[x].numOfNodes = 1;
    }
    for (int i = 1; i <= N; ++i)
        if (!findRoot[i])
        {
            root = i;
            break;
        }
    InOrderOfLevelTraversal(root);
    for (int i = N; i > 0; --i)
    {
        nodes[levelTra[i]].numOfNodes += nodes[nodes[levelTra[i]].left].numOfNodes + nodes[nodes[levelTra[i]].right].numOfNodes;
    }
    for (int i = 0; i < P; ++i)
    {
        scanf("%d %d", &root, &x);
        x = x % nodes[root].numOfNodes + 1;
        brushToRed(root, x);
    }

    for (int i = N; i > 0; --i)
    {
        nodes[levelTra[i]].numOfRed += nodes[nodes[levelTra[i]].left].numOfRed + nodes[nodes[levelTra[i]].right].numOfRed;
    }
    for (int i = 0; i < Q; ++i)
    {
        scanf("%d", &x);
        printf("%d\n", nodes[x].numOfRed);
    }
    return 0;
}