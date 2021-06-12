#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int64 int64_t

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }
    sort(a.rbegin(), a.rend());
    int64 first = 0, second = 0;
    for (int i = 0; i < 2 * k; i += 2) {
      first += a[i];
      second += a[i + 1];
    }
    second += a[2 * k];
    cout << max(first, second) << '\n';
  }
}