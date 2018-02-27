#include <iostream>
using namespace std;

int nums[10];

int main()
{
    int k, n = 0;
    cin >> k;
    for (nums[0] = 1; nums[0] < 10; ++nums[0])
    {
        ++n;
        if (k == n)
        {
            cout << nums[0] << 10 - nums[0];
            return 0;
        }
    }
    for (nums[0] = 1; nums[0] < 10; ++nums[0])
        for (nums[1] = 0; nums[1] <= 10 - nums[0]; ++nums[1])
        {
            ++n;
            if (k == n)
            {
                cout << nums[0] << nums[1] << 10 - nums[0] - nums[1];
                return 0;
            }
        }
    for (nums[0] = 1; nums[0] < 10; ++nums[0])
        for (nums[1] = 0; nums[1] <= 10 - nums[0]; ++nums[1])
            for (nums[2] = 0; nums[2] <= 10 - nums[0] - nums[1]; ++nums[2])
            {
                ++n;
                if (k == n)
                {
                    cout << nums[0] << nums[1] << nums[2] << 10 - nums[0] - nums[1] - nums[2];
                    return 0;
                }
            }
    for (nums[0] = 1; nums[0] < 10; ++nums[0])
        for (nums[1] = 0; nums[1] <= 10 - nums[0]; ++nums[1])
            for (nums[2] = 0; nums[2] <= 10 - nums[0] - nums[1]; ++nums[2])
                for (nums[3] = 0; nums[3] <= 10 - nums[0] - nums[1] - nums[2]; ++nums[3])
                {
                    ++n;
                    if (k == n)
                    {
                        cout << nums[0] << nums[1] << nums[2] << nums[3] << 10 - nums[0] - nums[1] - nums[2] - nums[3];
                        return 0;
                    }
                }
    for (nums[0] = 1; nums[0] < 10; ++nums[0])
        for (nums[1] = 0; nums[1] <= 10 - nums[0]; ++nums[1])
            for (nums[2] = 0; nums[2] <= 10 - nums[0] - nums[1]; ++nums[2])
                for (nums[3] = 0; nums[3] <= 10 - nums[0] - nums[1] - nums[2]; ++nums[3])
                    for (nums[4] = 0; nums[4] <= 10 - nums[0] - nums[1] - nums[2] - nums[3]; ++nums[4])
                    {
                        ++n;
                        if (k == n)
                        {
                            cout << nums[0] << nums[1] << nums[2] << nums[3] << nums[4] << 10 - nums[0] - nums[1] - nums[2] - nums[3] - nums[4];
                            return 0;
                        }
                    }
    for (nums[0] = 1; nums[0] < 10; ++nums[0])
        for (nums[1] = 0; nums[1] <= 10 - nums[0]; ++nums[1])
            for (nums[2] = 0; nums[2] <= 10 - nums[0] - nums[1]; ++nums[2])
                for (nums[3] = 0; nums[3] <= 10 - nums[0] - nums[1] - nums[2]; ++nums[3])
                    for (nums[4] = 0; nums[4] <= 10 - nums[0] - nums[1] - nums[2] - nums[3]; ++nums[4])
                        for (nums[5] = 0; nums[5] <= 10 - nums[0] - nums[1] - nums[2] - nums[3] - nums[4]; ++nums[5])
                        {
                            ++n;
                            if (k == n)
                            {
                                cout << nums[0] << nums[1] << nums[2] << nums[3] << nums[4] << nums[5] << 10 - nums[0] - nums[1] - nums[2] - nums[3] - nums[4] - nums[5];
                                return 0;
                            }
                        }
    for (nums[0] = 1; nums[0] < 10; ++nums[0])
        for (nums[1] = 0; nums[1] <= 10 - nums[0]; ++nums[1])
            for (nums[2] = 0; nums[2] <= 10 - nums[0] - nums[1]; ++nums[2])
                for (nums[3] = 0; nums[3] <= 10 - nums[0] - nums[1] - nums[2]; ++nums[3])
                    for (nums[4] = 0; nums[4] <= 10 - nums[0] - nums[1] - nums[2] - nums[3]; ++nums[4])
                        for (nums[5] = 0; nums[5] <= 10 - nums[0] - nums[1] - nums[2] - nums[3] - nums[4]; ++nums[5])
                            for (nums[6] = 0; nums[6] <= 10 - nums[0] - nums[1] - nums[2] - nums[3] - nums[4] - nums[5]; ++nums[6])
                            {
                                ++n;
                                if (k == n)
                                {
                                    cout << nums[0] << nums[1] << nums[2] << nums[3] << nums[4] << nums[5] << nums[6] << 10 - nums[0] - nums[1] - nums[2] - nums[3] - nums[4] - nums[5] - nums[6];
                                    return 0;
                                }
                            }
    return 0;
}