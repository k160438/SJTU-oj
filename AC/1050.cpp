#include <cstdio>
#include <queue>
using namespace std;
#define maxsize 300005

priority_queue<int, vector<int>, greater<int>> q[maxsize];

void f0()
{
    int a, b;
    scanf("%d %d", &a, &b);
    while (q[b].size())
    {
        q[a].push(q[b].top());
        q[b].pop();
    }
}

void f1()
{
    int a;
    scanf("%d", &a);
    if (q[a].size())
    {
        printf("%d\n", q[a].top());
        q[a].pop();
    }
    else
        printf("-1\n");
}

void f2()
{
    int a, b;
    scanf("%d %d", &a, &b);
    q[a].push(b);
}

int main()
{
    int n, m, op;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &op);
        q[i].push(op);
    }
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            f0();
            break;
        case 1:
            f1();
            break;
        default:
            f2();
        }
    }
    return 0;
}

// #include <cstdio>
// using namespace std;
// #define maxsize 300005

// struct linknode
// {
//     int data;
//     linknode *next;
// };

// linknode *q[maxsize];

// void f0()
// {
//     int a, b;
//     linknode *p, *t, *tmp;
//     scanf("%d %d", &a, &b);
//     p = q[a];
//     t = q[b];
//     q[b] = NULL;
//     tmp = new linknode;
//     q[a] = tmp;
//     while (p || t)
//     {
//         if (p && t)
//         {
//             if (p->data <= t->data)
//             {
//                 tmp->next = p;
//                 p = p->next;
//             }
//             else
//             {
//                 tmp->next = t;
//                 t = t->next;
//             }
//             tmp = tmp->next;
//             tmp->next = NULL;
//         }
//         else
//         {
//             if (t)
//                 tmp->next = t;
//             else
//                 tmp->next = p;
//             break;
//         }
//     }
//     tmp = q[a];
//     q[a] = q[a]->next;
//     delete tmp;
// }

// void f1()
// {
//     int a;
//     linknode *p;
//     scanf("%d", &a);
//     if (q[a])
//     {
//         p = q[a];
//         q[a] = q[a]->next;
//         printf("%d\n", p->data);
//         delete p;
//     }
//     else
//         printf("-1\n");
// }

// void f2()
// {
//     int a, b;
//     linknode *p, *tmp;
//     scanf("%d %d", &a, &b);
//     p = q[a];
//     if (p && q[a]->data < b)
//     {
//         while (p->next && p->next->data < b)
//             p = p->next;
//         tmp = p->next;
//         p->next = new linknode;
//         p->next->data = b;
//         p->next->next = tmp;
//     }
//     else
//     {
//         tmp = q[a];
//         q[a] = new linknode;
//         q[a]->data = b;
//         q[a]->next = tmp;
//     }
// }

// int main()
// {
//     int n, m, op;
//     scanf("%d %d", &n, &m);
//     for (int i = 0; i < n; ++i)
//     {
//         q[i] = new linknode;
//         scanf("%d", &op);
//         q[i]->data = op;
//         q[i]->next = NULL;
//     }
//     for (int i = 0; i < m; ++i)
//     {
//         scanf("%d", &op);
//         switch (op)
//         {
//         case 0:
//             f0();
//             break;
//         case 1:
//             f1();
//             break;
//         default:
//             f2();
//         }
//     }
//     return 0;
// }