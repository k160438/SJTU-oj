# include <iostream> 
using namespace std;
# define maxsize 10010

int A[maxsize];

int main(){
    int M, K;
    int l, position = 0;
    ios::sync_with_stdio(false);
    cin>>M;
    for(int i=0;i<M;++i)
        A[i] = i+1;
    for(int i=0;i<M-1;++i)
    {
        cin>>K;
        l = M-i;
        K = (K - 1) % l; // relative shift at position
        position = (position + K) % l;
        for(int j=position; j<l-1;++j)
            A[j] = A[j+1];
    }
    cout<<A[0]<<endl;
    return 0;
}