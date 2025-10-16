#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    while (true)
    {
        int N;
        cin >> N;
        vector<vector<int>> graph(N);
        if (N == 0)
            break;
        bool bicolorable = true;
        int L;
        cin >> L;
        for (int i = 0; i < L; i++)
        {
            int node1;
            int node2;
            cin >> node1 >> node2;
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }

        vector<int> color(N, -1);
        queue<int> q;
        color[0] = 0;
        q.push(0);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : graph[u])
            {
                if (color[v] == -1)
                {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if (color[v] == color[u])
                {
                    bicolorable = false;
                    break;
                }
            }
        }
        if (bicolorable)
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
    }

    return 0;
}