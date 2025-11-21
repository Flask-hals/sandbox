#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int sum, diff;
        cin >> sum >> diff;
        if (sum < diff || (sum + diff) % 2 != 0)
        {
            cout << "impossible" << endl;
            continue;
        }

        if ((sum - diff) / 2 < 0)
        {
            cout << "impossible" << endl;
            continue;
        }

        cout << (sum + diff) / 2 << " " << (sum - diff) / 2 << endl;
    }

    return 0;
}
/*
2
40 20
20 40
Sample Output
30 10
impossible
*/