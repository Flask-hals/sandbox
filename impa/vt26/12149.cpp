#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n {1};
    while (cin >> n && n != 0) {
        cout << (n * ((n + 1) * (2*n + 1))) / 6 << '\n';
    }

    return 0;
}