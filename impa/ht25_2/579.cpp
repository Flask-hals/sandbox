#include <iomanip>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
    string line;
    char delimeter;
    while (cin >> line)
    {
        if (line == "0:00")
            break;
        stringstream ss (line);
        int h, m;
        ss >> h >> delimeter >> m;
        h = h % 12;

        double degree = fabs(0.5 * (60 * h + m) - 6 * m);
        degree = min(360 - degree, degree);
        cout << fixed << setprecision(3) << degree << endl;
    }

    return 0;
}