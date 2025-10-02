#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct vIndex
{
    int index;
    int v;
};

vIndex findIndex(unordered_map<int, vector<int>>& um, int element)
{
    vIndex svi;
    for (int i = 0; i < um.size(); i++)
    {
        auto it = find(um[i].begin(), um[i].end(), element);
        if (it != um[i].end())
        {
            svi.index = distance(um[i].begin(), it);
            svi.v = i;
            break;
        }
    }
    return svi;
}

int main()
{
    unordered_map<int, vector<int>> um;
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        um[i] = {i};
    }
    while (true)
    {
        string line;
        cin >> line;
        if (line == "quit")
            break;
        else
        {
            if (line == "move")
            {
                int first;
                cin >> first;
                string ontoOver;
                cin >> ontoOver;
                if (ontoOver == "onto")
                {
                    int second;
                    cin >> second;
                    if (first == second)
                        continue;
                    auto a = findIndex(um, first);
                    int aIndex = a.index;
                    auto b = findIndex(um, second);
                    int bIndex = b.index;
                    int av = a.v;
                    int bv = b.v;
                    if (av == bv)
                        continue;
                    for (int i = um[av].size() - 1; i > aIndex; i--)
                    {
                        int last = um[av].back();
                        um[av].pop_back();
                        um[last].push_back(last); 
                    }
                    for (int i = um[bv].size() - 1; i > bIndex; i--)
                    {
                        int last = um[bv].back();
                        um[bv].pop_back();
                        um[last].push_back(last); 
                    }
                    int x = um[av].back();
                    um[av].pop_back();
                    um[bv].push_back(x);

                }
                else if (ontoOver == "over")
                {
                    int second;
                    cin >> second;
                    if (first == second)
                        continue;
                    auto a = findIndex(um, first);
                    int aIndex = a.index;
                    auto b = findIndex(um, second);
                    int av = a.v;
                    int bv = b.v;
                    if (av == bv)
                        continue;
                    for (int i = um[av].size() - 1; i > aIndex; i--)
                    {
                       int last = um[av].back();
                        um[av].pop_back();
                        um[last].push_back(last); 
                    }
                    int x = um[av].back();
                    um[av].pop_back();
                    um[bv].push_back(x);

                }
            }
            else if (line == "pile")
            {
                int first;
                cin >> first;
                string ontoOver;
                cin >> ontoOver;
                if (ontoOver == "onto")
                {
                    int second;
                    cin >> second;
                    if (first == second)
                        continue;
                    auto a = findIndex(um, first);
                    int aIndex = a.index;
                    auto b = findIndex(um, second);
                    int bIndex = b.index;
                    int av = a.v;
                    int bv = b.v;
                    if (av == bv)
                        continue;
                    vector<int> pile(um[av].begin() + aIndex, um[av].end());
                    um[av].erase(um[av].begin() + aIndex, um[av].end());
                    for (int i = um[bv].size() - 1; i > bIndex; i--)
                    {
                        int last = um[bv].back();
                        um[bv].pop_back();
                        um[last].push_back(last); 
                    }
                    um[bv].insert(um[bv].end(), pile.begin(), pile.end());
                }
                else if (ontoOver == "over")
                {
                    int second;
                    cin >> second;
                    if (first == second)
                        continue;
                    auto a = findIndex(um, first);
                    int aIndex = a.index;
                    auto b = findIndex(um, second);
                    int av = a.v;
                    int bv = b.v;
                    if (av == bv)
                        continue;
                    vector<int> pile(um[av].begin() + aIndex, um[av].end());
                    um[av].erase(um[av].begin() + aIndex, um[av].end());
                    um[bv].insert(um[bv].end(), pile.begin(), pile.end());
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << i << ":";
        for (int j = 0; j < um[i].size(); j++)
        {
            cout << " " << um[i][j];
        }
    cout << endl;
    }


    return 0;
}