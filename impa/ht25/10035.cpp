#include <iostream>

using namespace std;

int main()
{
    string n, m;
    while(cin >> n >> m && (n != "0" || m != "0"))
    {
        int sum {0};
        int carry {0};
        int carryCount {0};
        size_t lenN = n.length(), lenM = m.length();
        while (lenN != 0 || lenM != 0)
        {
            unsigned int x {0}, y {0};
            if (lenN > 0)
            {
                x = n[lenN-1] - '0';
                lenN--;
            }
            if (lenM > 0)
            {
                y = m[lenM-1] - '0';
                lenM--;
            }

            sum = x + y + carry;
            if (sum >= 10)
            {
                carry = 1;
                carryCount++;
            }
            else
            {
                carry = 0;
            }
            
        }
        if (carryCount == 0)
            cout << "No carry operation." << endl;
        else if (carryCount == 1)
            cout << carryCount << " carry operation." << endl;
        else
            cout << carryCount << " carry operations." << endl;
    }
    return 0;
}