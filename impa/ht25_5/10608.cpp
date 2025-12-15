#include <iostream>
#include <vector>

using namespace std;

class DisjointUnionSets
{
    vector<int> rank, parent, size;
    int maxSize {1};

public:

    DisjointUnionSets(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int i)
    {
        if (parent[i] != i)
        {
            return parent[i] = find(parent[i]);
        }

        return parent[i];
    }

    void unionSets(int x, int y)
    {
        int xRoot = find(x);
        int yRoot = find(y);

        if (xRoot == yRoot) return;

        if (rank[xRoot] < rank[yRoot])
        {
            parent[xRoot] = yRoot;
            size[yRoot] += size[xRoot];
            maxSize = max(maxSize, size[yRoot]);
        }
        else if (rank[yRoot] < rank[xRoot])
        {
            parent[yRoot] = xRoot;
            size[xRoot] += size[yRoot];
            maxSize = max(maxSize, size[xRoot]);
        }
        else
        {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
            size[xRoot] += size[yRoot];
            maxSize = max(maxSize, size[xRoot]);
        }
    }

    int getMaxSize()
    {
        return maxSize;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n, m;
        cin >> n >> m;
        DisjointUnionSets dus(n);
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            dus.unionSets(x-1, y-1);
        }

        cout << dus.getMaxSize() << "\n";
    }

    return 0;
}