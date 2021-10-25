#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

class solution {
  using int64 = int64_t;
  using ld = long double;

  const int kMod = 20011;

  void main() const {
    const int n = readInt(), m = readInt(), d = readInt();
    vector<vector<bool>> free(n + 2, vector<bool>(m + 2));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        free[i][j] = readInt();
      }
    }
    vector<vector<int>> up(n + 2, vector<int>(m + 2));
    vector<vector<int>> left(n + 2, vector<int>(m + 2));
    for (int r = 1; r <= min(n, d + 1); r++) {
      if (not free[r][1]) break;
      up[r][1] = 1;
    }
    for (int c = 1; c <= min(m, d + 1); c++) {
      if (not free[1][c]) break;
      left[1][c] = 1;
    }
    for (int r = 2; r <= n; r++) {
      for (int c = 2; c <= m; c++) {
        int cnt = 1;
        while (cnt <= d and free[r - cnt][c]) {
          up[r][c] += left[r - cnt][c];
          up[r][c] -= (up[r][c] >= kMod ? kMod : 0);
          cnt++;
        }
        cnt = 1;
        while (cnt <= d and free[r][c - cnt]) {
          left[r][c] += up[r][c - cnt];
          left[r][c] -= (left[r][c] >= kMod ? kMod : 0);
          cnt++;
        }
      }
    }
    print((left[n][m] + up[n][m]) % kMod), pline();
  }

public:
  explicit solution() {
    main();
  }

private:
  //inputting stuff (cin)
  [[maybe_unused]] static int readInt() {
    int x;
    cin >> x;
    return x;
  }
  [[maybe_unused]] static int64 readInt64() {
    int64 x;
    cin >> x;
    return x;
  }
  [[maybe_unused]] static string readString() {
    string s;
    cin >> s;
    return s;
  }
  [[maybe_unused]] static double readDouble() {
    return stod(readString());
  }
  [[maybe_unused]] static ld readLongDouble() {
    return stold(readString());
  }
  template<typename T1, typename T2>
  [[maybe_unused]] static pair<T1, T2> readPair() {
    pair<T1, T2> p;
    cin >> p.first >> p.second;
    return p;
  }
  template<typename T>
  [[maybe_unused]] static vector<T> readVec(const int sz) {
    vector<T> v(sz);
    for (T &x : v) {
      cin >> x;
    }
    return v;
  }
  template<typename T>
  [[maybe_unused]] static vector<vector<T>> readVecVec(const int n, const int m) {
    vector<vector<T>> a(n);
    for (vector<T> &v : a) {
      v = readVec<T>(m);
    }
    return a;
  }

  //outputting stuff (cout)
  [[maybe_unused]] static void pline() { cout << '\n'; }
  [[maybe_unused]] static void pspace() { cout << ' '; }
  [[maybe_unused]] static void print(const int x) { cout << x; }
  [[maybe_unused]] static void print(const unsigned int x) { print(int(x)); }
  [[maybe_unused]] static void print(const int64 x) { cout << x; }
  [[maybe_unused]] static void print(const double d, const int precision = 10) { cout << fixed << setprecision(precision) << d; }
  [[maybe_unused]] static void print(const ld d, const int precision = 10) { cout << fixed << setprecision(precision) << d; }
  [[maybe_unused]] static void print(const char c) { cout << c; }
  [[maybe_unused]] static void print(const string &s) { cout << s; }
  template<typename T1, typename T2>
  [[maybe_unused]] static void print(const pair<T1, T2> &p) { print(p.first), pspace(), print(p.second); }
  template<typename T>
  [[maybe_unused]] static void print(const vector<T> &v) {
    for (const T &x : v) {
      print(x), pspace();
    }
    pline();
  }
  template<typename T>
  [[maybe_unused]] static void print(const vector<vector<T>> &a) {
    for (const vector<T> &v : a) {
      print(v);
    }
  }

  //debugging stuff (cerr)
  [[maybe_unused]] static void _pline() { cerr << '\n'; }
  [[maybe_unused]] static void _pspace() { cerr << ' '; }
  [[maybe_unused]] static void _print(const int x) { cerr << x; }
  [[maybe_unused]] static void _print(const int64 x) { cerr << x; }
  [[maybe_unused]] static void _print(const unsigned int x) { cerr << x; }
  [[maybe_unused]] static void _print(const double d, const int precision = 10) { cerr << fixed << setprecision(precision) << d; }
  [[maybe_unused]] static void _print(const ld d, const int precision = 10) { cerr << fixed << setprecision(precision) << d; }
  [[maybe_unused]] static void _print(const char c) { cerr << '\'' << c << '\''; }
  [[maybe_unused]] static void _print(const string &s) { cerr << '\"' << s << '\"'; }
  template<typename T1, typename T2>
  [[maybe_unused]] static void _print(const pair<T1, T2> &p) {
    cerr << '[';
    _print(p.first);
    cerr << ", ";
    _print(p.second);
    cerr << ']';
  }
  template<typename T>
  [[maybe_unused]] static void _print(const vector<T> &v) {
    for (const T &x : v) {
      _print(x), _pspace();
    }
    _pline();
  }
  template<typename T>
  [[maybe_unused]] static void _print(const vector<vector<T>> &a) {
    for (const vector<T> &v : a) {
      _print(v);
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const auto begin = std::chrono::high_resolution_clock::now();

  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);

  int t = 1;
  //cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solution();
  }

  const auto end = std::chrono::high_resolution_clock::now();
  const auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}