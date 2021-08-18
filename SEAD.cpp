#include <algorithm>
#include <array>
#include <cassert>
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

template<typename T, class F = function<T(const T &, const T &)>>
class SparseTable {
  const int n;
  vector<vector<T>> table;
  const F unite;

public:
  explicit SparseTable(const vector<T> &a, const F &f) : n(static_cast<int>(a.size())), unite(f) {
    int log = 32 - __builtin_clz(n);
    table.resize(log);
    table[0] = a;
    for (int j = 1; j < log; j++) {
      table[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        table[j][i] = unite(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T get(const int l, const int r) const {
    assert(0 <= l && l <= r && r <= n - 1);
    const int log = 32 - __builtin_clz(r - l + 1) - 1;
    return unite(table[log][l], table[log][r - (1 << log) + 1]);
  }
};

/*
5
1 2 3 10 50
1
11 7
*/

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  a.push_back(kInf);
  vector<int> diff(n);
  for (int i = 0; i < n; i++) {
    diff[i] = a[i + 1] - a[i];
  }
  SparseTable<int> mx(diff, [](const int x, const int y) {
    return max(x, y);
  });
  auto binary_search = [&](const int t, const int d, const int r) -> int {
    int lo = 0, hi = r;
    while (lo < hi) {
      const int mid = (lo + hi) / 2;
      if (mx.get(mid, r - 1) <= d) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    return lo;
  };
  int q;
  cin >> q;
  while (q--) {
    int t, d;
    cin >> t >> d;
    cout << binary_search(t, d, distance(a.begin(), prev(upper_bound(a.begin(), a.end(), t)))) + 1 << '\n';
  }
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