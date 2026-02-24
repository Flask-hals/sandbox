#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    while(cin >> n && n != 0)
    {
        multiset<int> ms;
        long long totalCost {0};
        for(int day = 0; day < n; day++)
        {
            int k;
            cin >> k;
            
            while(k--)
            {
                int bill;
                cin >> bill;
                ms.insert(bill);
            }
            auto low = ms.begin();
            auto high = prev(ms.end());
            totalCost += (long long)*high - *low;
            ms.erase(low);
            ms.erase(high);
        }
        cout << totalCost << endl;
    }

    return 0;
}