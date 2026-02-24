#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, f;
    while(cin >> l >> f && (l != 0 || f != 0)) {
        double v = sqrt(2 * f * l);

        double d = pow(v, 2) / (2 * f);

        double volume = (3600 * v) / (d + l);

        cout << setprecision(8) << fixed << v << " " << volume << '\n';
    }

    return 0;
}