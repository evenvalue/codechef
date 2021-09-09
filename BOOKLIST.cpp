#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
using int64 = int64_t;

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

ifstream fin("input.txt");
ofstream fout("output.txt");

class segtree {
  const int n;
  vector<int> t;

  static int unite(const int l, const int r) {
    return l + r;
  }

  void build(const int x, const int l, const int r) {
    if (l == r) {
      t[x] = 1;
      return;
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    build(x + 1, l, mid);
    build(y, mid + 1, r);
    t[x] = unite(t[x + 1], t[y]);
  }

  void update(const int x, const int l, const int r, const int pos) {
    if (l == r) {
      t[x] = 0;
      return;
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (pos <= mid) {
      update(x + 1, l, mid, pos);
    } else {
      update(y, mid + 1, r, pos);
    }
    t[x] = unite(t[x + 1], t[y]);
  }

  int find_first(const int x, const int l, const int r, const int i) {
    if (l == r) {
      return l;
    }
    const int mid = (l + r) / 2;
    const int y = 2 * (mid - l + 1) + x;
    if (t[x + 1] >= i) {
      return find_first(x + 1, l, mid, i);
    } else {
      return find_first(y, mid + 1, r, i - t[x + 1]);
    }
  }

public:
  explicit segtree(const int n) : n(n), t(2 * n - 1) {
    build(0, 0, n - 1);
  }

  int first(const int i) {
    assert(t[0] >= i);
    const int idx = find_first(0, 0, n - 1, i);
    update(0, 0, n - 1, idx);
    return idx;
  }
};

void solve(const int TestCase) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  segtree st(n);
  int q;
  cin >> q;
  while (q--) {
    int book;
    cin >> book;
    const int idx = st.first(book);
    cout << a[idx] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto begin = std::chrono::high_resolution_clock::now();

  int t = 1;
  //cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve(tc);
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}