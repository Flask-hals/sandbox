#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findNext(const vector<int>& v, int start, int k)
{
    while(k > 0)
    {
        start = (start + 1) % v.size();
        if (v[start] != 0)
            k--;
    }

    return start;
}

int main()
{
    int n, k;
    while(cin >> n >> k && (n != 0 || k != 0))
    {
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        for (int start = 1; start <= n; start++)
        {
            vector<int> v(n);
            
            for (int i = 1; i <= n; i++)
            {
                v[i-1] = i;
            }

            int current {(start - 1 + k - 1) % n};
            int deadcount {0};
            while (deadcount != v.size() - 1)
            {
                v[current] = 0;
                
                int swapper = findNext(v, current, k);
                
                swap(v[current], v[swapper]);
                
                current = findNext(v, current, k);

                deadcount++;
            }
            bool breaker {false};
            for (int i = 0; i < n; i++)
            {
                if (v[i] != 0)
                {
                    if (v[i] == 1)
                    {
                        cout << start << endl;
                        breaker = true;
                        break;
                    }
                }
            }
            if (breaker)
                break;
        }
    }

    return 0; 
}