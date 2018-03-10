#include <iostream>
#include <algorithm>
using namespace std;
#define maxsize 105

int input[maxsize];
int f[maxsize][maxsize] = {0};

int main()
{
    int n, i, j, k, energy = 0;
    cin >> n;
    for (i = 0; i < n; ++i)
    {
        cin >> input[i];
    }
    for (int l = 1; l < n; ++l)
        for (int i = 0; i < n; ++i)
        {
            int j = i + l;
            for (int k = i; k < j; ++k)
            {

                f[i][j % n] = max(f[i][j % n], f[i][k % n] + f[(k + 1) % n][j % n] + input[i] * input[(k + 1) % n] * input[(j + 1) % n]);
            }
        }
    energy = f[0][n - 1];
    for (int i = 1; i < n; ++i)
        energy = max(energy, f[i][i - 1]);
    cout << energy << endl;

    return 0;
}
