#include <iostream>
#include <cmath>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    double k1, k2, k3, v;
    cin >> k1 >> k2 >> k3 >> v;
    const double time = 100 / (k1 * k2 * k3 * v);
    cout << ((floor(time * 100 + 0.5) / 100) < 9.58 ? "YES" : "NO") << '\n';
  }
}