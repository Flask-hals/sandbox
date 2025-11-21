#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> edges = {
    {1,2}, {1,3}, {1,5},
    {2,3}, {2,5},
    {3,4}, {3,5},
    {4,5}
};

void findAllPaths(int current, vector<int>& path, vector<bool>& used, vector<vector<int>>& allPaths)
{
    if (path.size() == 9)
    {
        allPaths.push_back(path);
        return;
    }
    
    for (int i = 0; i < edges.size(); i++)
    {
        if (used[i]) continue;
        
        int a = edges[i].first;
        int b = edges[i].second;
        
        if (current == a || current == b)
        {
            int next = (current == a) ? b : a;
            
            used[i] = true;
            path.push_back(next);
            
            findAllPaths(next, path, used, allPaths);
            
            path.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
    vector<vector<int>> allPaths;
    vector<int> path = {1};
    vector<bool> used(edges.size(), false);
    
    findAllPaths(1, path, used, allPaths);
    
    for (const auto& p : allPaths)
    {
        for (int node : p)
        {
            cout << node;
        }
        cout << endl;
    }
    
    return 0;
}
