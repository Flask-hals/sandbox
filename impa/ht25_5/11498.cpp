#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n, m;
    while(cin >> k && k != 0) {
        cin >> n >> m;
        int x, y;

        while (k--) {
            cin >> x >> y;
            if (x == n || y == m) {
                cout << "divisa" << "\n";
            }
            else if (x > n && y > m) {
                cout << "NE" << "\n";
            }
            else if (x > n && y < m) {
                cout << "SE" << "\n";
            }
            else if (x < n && y > m) {
                cout << "NO" << "\n";
            }
            else if (x < n && y < m) {
                cout << "SO" << "\n";
            }
        }
    }

    return 0;
}