#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, string> dict;
    stringstream ss;
    string x, y;
    while(getline(cin, x) && !x.empty())
    {
        ss.clear();
        ss.str(x);
        ss >> x >> y;
        dict[y] = x;
    }

    string sequence;
    while (getline(cin, sequence) && !sequence.empty())
    {
        ss.clear();
        ss.str(sequence);
        ss >> sequence;
        auto it = dict.find(sequence);
        if (it != dict.end())
        {
            cout << it->second << "\n";
        }
        else
        {
            cout << "eh\n";
        }
    }

    return 0;
}