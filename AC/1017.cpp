#include <iostream>
#include <algorithm>
using namespace std;

int nums[1002][3000] = {{0}};

void simplify(int n)
{
    int i = 1, j = 0;
    while (j > 0 || i <= nums[n][0])
    {
        nums[n][i] += j;
        j = nums[n][i] / 10;
        nums[n][i] %= 10;
        ++i;
    }
    nums[n][0] = i - 1;
}

int main()
{
    int a, b, c, N;
    cin >> a >> b >> c >> N;
    nums[0][0] = nums[1][0] = nums[2][0] = nums[0][1] = 1;
    nums[1][1] = a + 1;
    nums[2][1] = a * a + b + a + 1;
    simplify(1);
    simplify(2);
    for (int i = 3; i <= N; ++i)
    {
        int j;
        for (j = 1; j <= nums[i - 3][0]; ++j)
            nums[i][j] += (c - b) * nums[i - 3][j];
        for (j = 1; j <= nums[i - 2][0]; ++j)
            nums[i][j] += (b - a) * nums[i - 2][j];
        for (j = 1; j <= nums[i - 1][0]; ++j)
            nums[i][j] += (a + 1) * nums[i - 1][j];
        nums[i][0] = nums[i - 1][0];
        simplify(i);
    }
    for (int i = nums[N][0]; i > 0; --i)
        cout << nums[N][i];
    return 0;
}