#include <cmath>
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int tx, ty, jx, jy;
    int k;
    cin >> tx >> ty >> jx >> jy >> k;
    int dist = abs(tx - jx) + abs(ty - jy);
    cout << (dist <= k and ((dist & 1) == (k & 1)) ? "YES" : "NO") << '\n';
  }
}
