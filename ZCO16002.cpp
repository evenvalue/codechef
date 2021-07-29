#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
using int64 = int64_t;

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  vector<bool> is_there(*max_element(a.begin(), a.end()) + 1, false);
  for (int &x : a) is_there[x] = true;
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int len = 0;
      int x = a[i];
      while (is_there[x]) {
        len++;
        x += a[j] - a[i];
      }
      ans = max(ans, len);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  while (t--) {
    solve();
  }
}