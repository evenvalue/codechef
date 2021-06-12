#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }
    cout << 2 * (*max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end())) << "\n";
  }
}
