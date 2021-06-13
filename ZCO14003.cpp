#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int64 int64_t

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  sort(a.rbegin(), a.rend());
  int64 ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, (int64) a[i] * (i + 1));
  }
  cout << ans << '\n';
}