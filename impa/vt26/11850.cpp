#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define sort(a) sort(a.begin(), a.end());

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    while(cin >> n && n != 0) {
        int station;
        vector<int> stations;
        for (int i = 0; i < n; i++) {
            cin >> station;
            stations.push_back(station);
        }

       sort(stations);

        bool impossible {false};
        for (int i = 1; i < n; i++) {
            int dist {0};
            if (i == n-1) {
                dist = (1422 - stations[i]) * 2;
                if (stations[i] - stations[i-1] > 200) {
                    impossible = true;
                    break;
                }
            } else {
                dist = stations[i] - stations[i-1];
            }

            if (dist > 200) {
                impossible = true;
                break;
            }
        }

        if (!impossible) {
            cout << "POSSIBLE" << '\n';
        } else {
            cout << "IMPOSSIBLE" << '\n';
        }
    }

    return 0;
}