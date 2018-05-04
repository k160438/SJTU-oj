#include <iostream>
#include <string>
using namespace std;

template <class T>
class hfTree
{
  private:
    struct Node
    {
        int freq;
        T data;
        int left, right, parent;
    };
    Node *head;
    int length;

  public:
    struct hfCode
    {
        T data;
        string code;
    };
    hfTree() {}
    void create(const T *data, const int *freq, int len);
    void getCode(hfCode res[]) const;
};

template <class T>
void hfTree<T>::create(const T *data, const int *freq, int len)
{
    length = len;
    head = new Node[2 * length];
    for (int i = 2 * length - 1; i > length - 1; --i)
    {
        head[i].left = 0;
        head[i].right = 0;
        head[i].parent = 0;
        head[i].data = data[i - length];
        head[i].freq = freq[i - length];
    }
    for (int i = length - 1; i > 0; --i)
    {
        int Min[2][2];
        Min[0][0] = Min[1][0] = 2147483640;
        for (int j = i + 1; j < 2 * length; ++j)
            if (head[j].parent == 0 && head[j].freq < Min[1][0])
            {
                if (head[j].freq < Min[0][0])
                {
                    Min[1][0] = Min[0][0];
                    Min[1][1] = Min[0][1];
                    Min[0][0] = head[j].freq;
                    Min[0][1] = j;
                }
                else
                {
                    Min[1][0] = head[j].freq;
                    Min[1][1] = j;
                }
            }
        head[Min[0][1]].parent = i;
        head[Min[1][1]].parent = i;
        head[i].left = Min[0][1];
        head[i].right = Min[1][1];
        head[i].freq = Min[0][0] + Min[1][0];
        head[i].parent = 0;
    }
}

template <class T>
void hfTree<T>::getCode(hfCode res[]) const
{
    int p;
    for (int i = 0; i < length; ++i)
    {
        res[i].data = head[i + length].data;
        p = i + length;
        while (head[p].parent > 0)
        {
            if (head[head[p].parent].left == p)
                res[i].code = '0' + res[i].code;
            else
                res[i].code = '1' + res[i].code;
            p = head[p].parent;
        }
    }
}

int main()
{
    char ch[] = {"aeistdn"};
    int w[] = {10, 15, 12, 2, 4, 13, 1};
    hfTree<char> tree;
    tree.create(ch, w, 7);
    hfTree<char>::hfCode result[7];
    tree.getCode(result);
    for (int i = 0; i < 7; ++i)
        cout << result[i].data << ' ' << result[i].code << endl;
    return 0;
}