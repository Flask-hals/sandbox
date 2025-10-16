#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node
{
    int degree;
    vector<pair<char, int>> neighbors;
};

int dijkstras(unordered_map<char, Node> nodes, char& from, char& to)
{
    return 0;
}

int checkIfOdd(unordered_map<char, Node> nodes)
{
    int extra {0};
    vector<char> oddNodes;
    for (auto &kv : nodes)
    {
        if (kv.second.degree % 2 != 0)
            oddNodes.push_back(kv.first);
        if (oddNodes.size() == 2)
        {
            extra = dijkstras(nodes, oddNodes[0], oddNodes[1]);
            break;
        }
    }
    return extra;
}

int main()
{
    string street;
    unordered_map<char, Node> nodes;
    int totalLenght {0};
    while(cin >> street)
    {
        if (street == "deadend")
            break;

        nodes[street.front()].neighbors.push_back({street.back(), street.length()});
        nodes[street.back()].neighbors.push_back({street.front(), street.length()});
        nodes[street.front()].degree++;
        nodes[street.back()].degree++;
        totalLenght += street.length();
    }
    totalLenght += checkIfOdd(nodes);
    cout << totalLenght << endl;

    return 0;
}
/*
one
two
three
deadend
mit
dartmouth
linkoping
tasmania
york
emory
cornell
duke
kaunas
hildesheim
concord
arkansas
williams
glasgow
deadend
Sample Output
11
114
*/