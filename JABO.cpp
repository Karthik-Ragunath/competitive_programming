#include <cassert>
#include <cstdio>
#include <vector>

using namespace std;

/*
 * Weighted Union with Path Compression
 */
class WUPC
{
public:
    WUPC(int s) : parent(s), size(s, 1), sources(s, 0)
    {
        vector<int>::iterator vit;
        int i;
        for (i = 0, vit = parent.begin(); vit != parent.end(); vit++, i++)
            *vit = i;
    }
    void join(int a, int b);
    bool getPotential(int a)
    {
        int ns = sources[root(a)];
        assert(ns >= 0);
        return ns != 0;
    }
    void setPotential(int a)
    {
        sources[root(a)]++;
    }
    void unsetPotential(int a)
    {
        sources[root(a)]--;
    }

private:
    vector<int> parent;
    vector<int> size;
    vector<int> sources;

    int root(int a);
};

void WUPC::join(int a, int b)
{
    int rootA = root(a);
    int rootB = root(b);

    if (rootA != rootB)
    {
        if (size[rootA] < size[rootB])  //Weighted Union
        {
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
            sources[rootB] += sources[rootA];
        }
        else
        {
            parent[rootB]= rootA;
            size[rootA] += size[rootB];
            sources[rootA] += sources[rootB];
        }
    }
}

int WUPC::root(int a)
{
    while (a != parent[a])
    {
        parent[a] = parent[parent[a]];  //Path Compression
        a = parent[a];
    }
    return a;
}

inline int map(int x, int y, int c)
{
    return ((y-1)/5)*c + x - 1;
}

int dec(char s[])
{
    int r;
    if (s[0] & 32)
        r = s[0] - 'a' + 26;
    else
        r = s[0] - 'A';
    r *= 52;
    if (s[1] & 32)
        r += s[1] - 'a' + 26;
    else
        r += s[1] - 'A';
    return r;
}

int main()
{
    int n, r, c, a, x1, x2, y1, y2;
    char s[16];

    scanf("%d %d %d", &n, &r, &c);

    WUPC wupc(c*r);

    while (n--)
    {
        scanf("%s", s);
        switch (s[0])
        {
            case 'W':
                x1 = dec(s + 1);
                y1 = dec(s + 3);
                x2 = dec(s + 5);
                y2 = dec(s + 7);
                wupc.join(map(x1, y1, c), map(x2, y2, c));
                break;

            case 'V':
                x1 = dec(s + 1);
                y1 = dec(s + 3);
                wupc.setPotential(map(x1, y1, c));
                break;

            case 'R':
                x1 = dec(s + 1);
                y1 = dec(s + 3);
                    wupc.unsetPotential(map(x1, y1, c));
                    break;

            case 'L':
                x1 = dec(s + 1);
                y1 = dec(s + 3);
                x2 = dec(s + 5);
                y2 = dec(s + 7);
                if (wupc.getPotential(map(x1, y1, c)) !=
                        wupc.getPotential(map(x2, y2, c)))
                    printf("ON\n");
                else
                    printf("OFF\n");
                break;
        }
    }

    return 0;
}

