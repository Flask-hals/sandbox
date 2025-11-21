#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REVERSE(x) reverse((x).begin(), (x).end());

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string a, b;
        cin >> a >> b;

        vector<int> av;
        vector<int> bv;

        for (char c : a)
            av.push_back(c - '0');
        for (char c : b)
            bv.push_back(c - '0');

        while (av.size() > 1 && av.back() == 0) av.pop_back();
        while (bv.size() > 1 && bv.back() == 0) bv.pop_back();

        while (bv.size() < av.size()) bv.push_back(0);
        while (av.size() < bv.size()) av.push_back(0);

        REVERSE(av);
        REVERSE(bv);

        vector<int> result;

        int carry {0};

        for (int i = av.size() - 1; i >= 0; i--)
        {
            int abSum = av[i] + bv[i] + carry;
            carry = 0;
            if (abSum >= 10)
            {
                carry = 1;
                result.push_back(abSum - 10);
                continue;
            }
            result.push_back(abSum);
        }
        if (carry)
            result.push_back(carry);


        REVERSE(result);

        while (result.size() > 1 && result.back() == 0) result.pop_back();

        REVERSE(result);

        for (int i : result)
            cout << i;
        cout << endl;
    }

    return 0;
}