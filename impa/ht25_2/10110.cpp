#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long n;
    while(cin >> n && n != 0)
    {
        double i = sqrt(n);
        int x = i;
        if (x == i)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}