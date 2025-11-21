#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> vr;
    while(n--)
    {
        string result;
        vector<int> v;
        int m;
        cin >> m;
        while(m--)
        {
            int x, y;
            cin >> x >> y;
            int tmp = x + y;
            v.push_back(tmp);
        }

        for (int i = v.size(); i > 0; i--)
        {
            if (v[i] >= 10)
            {
                v[i-1] += 1;
                v[i] -= 10;
            }
        }

        for (int i : v)
        {
            result += to_string(i);
        }
        vr.push_back(result);
    }
    for (int i = 0; i < vr.size(); i++)
    {
        cout << vr[i] << endl;
        if (i != vr.size() - 1)
            cout << '\n';
    }
    return 0;
}