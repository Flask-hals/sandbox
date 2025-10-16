#include <iomanip>
#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <queue>

using namespace std;

struct Stone
{
    int x, y;
};

double hypo(double x, double y, double x2, double y2)
{
    return sqrt(((x2-x) * (x2-x)) + ((y2-y) * (y2-y)));
}

double minmaxDijkstra(int Freddy, int Fiona, vector<Stone>& stones)
{
    vector<double> distance(stones.size(), numeric_limits<double>::infinity());
    distance[Freddy] = 0;

    priority_queue<pair<double, int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
    pq.push({0.0, Freddy});

    while (!pq.empty())
    {
        auto [currMaxHop, stone] = pq.top(); pq.pop();

        if (currMaxHop > distance[stone])
            continue;

        for (int v = 0; v < stones.size(); v++)
        {
            if (v == stone)
                continue;
            double weight = hypo(stones[stone].x, stones[stone].y, stones[v].x, stones[v].y);
            double maxHop = max(distance[stone], weight);
            if (distance[v] > maxHop)
            {
                distance[v] = maxHop;
                pq.push({distance[v], v});
            }
        }
    }
    return distance[Fiona];

}

int main()
{
    int scenario = 0;
    int n;
    while (cin >> n && n != 0)
    {
        scenario++;
        vector<Stone> stones(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stones[i].x;
            cin >> stones[i].y;
        }

        cout << "Scenario #" << scenario << endl;
        cout << "Frog Distance = " << fixed << setprecision(3) << minmaxDijkstra(0, 1, stones) << endl;
        cout << endl;
    }
    return 0;
}