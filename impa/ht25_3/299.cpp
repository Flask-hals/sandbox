#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int l, element {0}, swaps {0};
        cin >> l;
        if (l == 0)
        {
            cout << "Optimal train swapping takes 0 swaps." << endl;
            continue;
        }
        vector<int> v(l);

        for (int k = 0; k < l; k++)
            cin >> v[k];

        for (size_t j = 0; j < v.size(); j++)
        {
            for (size_t i = j + 1; i < v.size(); i++)
            {
                if (v[j] > v[i])
                {
                    swaps++;
                }
            }
        }
        cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
    }
    return 0;
}
/*
3
3
1 3 2
4
4 3 2 1
2
2 1
Sample Output
Optimal train swapping takes 1 swaps.
Optimal train swapping takes 6 swaps.
Optimal train swapping takes 1 swaps.
*/