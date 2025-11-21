#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int createKeys(const vector<int> v)
{
    int key = 0;
        for (int i = 0; i < v.size(); ++i)
            if (v[i]) key |= (1 << i);
    return key;
}

int dfs(vector<int> v, unordered_map<int, int> um)
{
    int key = createKeys(v);

    if (um.count(key)) return um[key];

    int min_pebbles = 0;
    for (int x : v)
        min_pebbles += x;

    for (int i = 0; i < 10; i++)
    {
        if (v[i] == 1 && v[i+1] == 1 && v[i+2] == 0)
        {
            vector<int> nv = v;
            nv[i] = 0;
            nv[i+1] = 0;
            nv[i+2] = 1;
            min_pebbles = min(dfs(nv, um), min_pebbles);
        }

        if (v[i] == 0 && v[i+1] == 1 && v[i+2] == 1)
        {
            vector<int> nv = v;
            nv[i] = 1;
            nv[i+1] = 0;
            nv[i+2] = 0;
            min_pebbles = min(dfs(nv, um), min_pebbles);
        }
    }
    um[key] = min_pebbles;
    return min_pebbles;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        unordered_map<int, int> um;
        vector<int> v;
        string line;
        cin >> line;
        for (const char c : line)
        {
            if (c == '-')
                v.push_back(0);
            else
                v.push_back(1);
        }

        cout << dfs(v, um) << endl;
     
    }
    return 0;
}