#include <algorithm>
#include <iostream>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    while (cin >> a >> b && (a != -1 || b != -1)) {
        int ans = min((b - a + 100) % 100, (a - b + 100) % 100);
        cout << ans << '\n';
    }


    return 0;
}