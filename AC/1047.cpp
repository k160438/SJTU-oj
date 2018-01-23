#include <iostream>
using namespace std;

int op[9][9] = {
    {1, 1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 0, 1, 1}};
int scores[9] = {4, 3, 4, 3, 5, 3, 4, 3, 4};
int input[9], num[9], trial[9], res[9];

bool isLawful()
{
    int i, j;
    for (i = 0; i < 9; ++i)
        for (j = 0; j < 9; ++j)
            trial[i] += op[j][i] * num[j];
    for (i = 0; i < 9; ++i)
    {
        trial[i] %= 4;
        if (trial[i])
            return false;
    }
    return true;
}

int calscore()
{
    int res = 0;
    for (int i = 0; i < 9; ++i)
        res += scores[i] * num[i];
    return res;
}

int callen(int t)
{
    int res = 0;
    for (int i = 0; i < t; ++i)
        res += num[i];
    return res;
}

int main()
{
    int tmp, len, minlen = 100, score, minscore = 180;
    for (int i = 0; i < 9; ++i)
    {
        cin >> tmp;
        input[i] = tmp / 3;
    }
    for (num[0] = 0; num[0] < 4; num[0] += 1)
    {
        len = num[0];
        if (len > minlen)
            break;
        else
            for (num[1] = 0; num[1] < 4; num[1] += 1)
                if (callen(2) > minlen)
                    break;
                else
                    for (num[2] = 0; num[2] < 4; num[2] += 1)
                        if (callen(3) > minlen)
                            break;
                        else
                            for (num[3] = 0; num[3] < 4; num[3] += 1)
                                if (callen(4) > minlen)
                                    break;
                                else
                                    for (num[4] = 0; num[4] < 4; num[4] += 1)
                                        if (callen(5) > minlen)
                                            break;
                                        else
                                            for (num[5] = 0; num[5] < 4; num[5] += 1)
                                                if (callen(6) > minlen)
                                                    break;
                                                else
                                                    for (num[6] = 0; num[6] < 4; num[6] += 1)
                                                        if (callen(7) > minlen)
                                                            break;
                                                        else
                                                            for (num[7] = 0; num[7] < 4; num[7] += 1)
                                                                if (callen(8) > minlen)
                                                                    break;
                                                                else
                                                                    for (num[8] = 0; num[8] < 4; num[8] += 1)
                                                                        if ((len = callen(9)) > minlen)
                                                                            break;
                                                                        else
                                                                        {
                                                                            for (int i = 0; i < 9; ++i)
                                                                                trial[i] = input[i];

                                                                            if (isLawful())
                                                                            {

                                                                                score = calscore();
                                                                                if ((len == minlen && score < minscore) || len < minlen)
                                                                                {
                                                                                    minlen = len;
                                                                                    minscore = score;
                                                                                    for (int i = 0; i < 9; ++i)
                                                                                        res[i] = num[i];
                                                                                }
                                                                            }
                                                                        }
    }

    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < res[i]; ++j)
            cout << i + 1 << ' ';
    return 0;
}