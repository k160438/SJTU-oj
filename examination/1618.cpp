# include <cstdio> 
# include <queue> 
# include <vector>
using namespace std;
# define maxsize 100010

int A[maxsize];
int max_res[maxsize], min_res[maxsize];
int n, k;

struct node
{
    int value, index;
    node(int a, int b):value(a), index(b){}
    bool operator<(const node &a) const
    {
        return value < a.value;
    }
    bool operator>(const node &a) const
    {
        return value > a.value;
    }
};


int main()
{
    scanf("%d%d", &n, &k);
    priority_queue<node, std::vector<node>, greater<node>> minimum;
    priority_queue<node, std::vector<node>, less<node>> maximum;

    for(int i=0;i<n;++i){
        scanf("%d", &A[i]);
    }
    for(int i=0;i<k;++i)
    {
        minimum.push(node(A[i], i));
        maximum.push(node(A[i], i));
    }
    max_res[0] = maximum.top().value;
    min_res[0] = minimum.top().value;
    for(int i=1;i<=n-k;++i)
    {
        while(maximum.top().index<i)
            maximum.pop();
        while(minimum.top().index<i)
            minimum.pop();
        maximum.push(node(A[i+k-1], i+k-1));
        minimum.push(node(A[i+k-1], i+k-1));
        max_res[i] = maximum.top().value;
        min_res[i] = minimum.top().value;
    }
    for(int i=0;i<=n-k;++i)
        printf("%d ", min_res[i]);
    printf("\n");
    for(int i=0;i<=n-k;++i)
        printf("%d ", max_res[i]);
    printf("\n");
    return 0;
}