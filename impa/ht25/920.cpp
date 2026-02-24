#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int C;
  cin >> C;
  for (int i = 0; i < C; i++) {
    int lines = 0;
    cin >> lines;
    double maxY = 0;
    bool first = true;
    double sum = 0;
    vector<pair<double, double>> v;
    double lastX;
    double lastY;
    bool firstTop = true;

    for (int i = 0; i < lines; i++) {
      double x;
      double y;
      cin >> x >> y;
      v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end(),
         [](pair<double, double> a, pair<double, double> b) {
           return a.first > b.first;
         });

    for (auto i : v) {
      if (first) {
        maxY = i.second;
        first = false;
        lastX = i.first;
        lastY = i.second;

      } else {
        if (firstTop) {
          sum += sqrt(pow((i.first - lastX), 2) + pow((i.second - lastY), 2));
          firstTop = false;
          lastX = i.first;
          lastY = i.second;
          maxY = i.second;
        } else {
          if (i.second > maxY) {
            double tmp = 0;
            tmp = lastX +
                  ((maxY - lastY) * (i.first - lastX) / (i.second - lastY));
            sum += sqrt(pow((i.first - tmp), 2) + pow((i.second - maxY), 2));
            maxY = i.second;
          }
          lastX = i.first;
          lastY = i.second;
        }
      }
    }
    cout << fixed << setprecision(2) << sum << endl;
  }
  return 0;
}