#include <iostream>

using namespace std;

int main() {
  int N;
  int A;
  long long sum = 0;

  while (cin >> N >> A) {
    long long power = 1;
    for (int i = 1; i <= N; i++) {
      power *= A;
      sum += i * power;
    }

    cout << sum << endl;
    sum = 0;
  }

  return 0;
}