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

  const int64 kInf = 1e15;
  vector<vector<pair<int, int>>> g;

  vector<int64> dijkstra(const int source) {
    const int n = g.size();
    vector<int64> dist(n, kInf);
    priority_queue<pair<int64, int>, vector<pair<int64, int>>, greater<>> q;
    dist[source] = 0;
    q.push({0, source});
    while (not q.empty()) {
      const int64 d = q.top().first;
      const int x = q.top().second;
      q.pop();
      if (d > dist[x]) continue;
      for (const pair<int, int> p : g[x]) {
        const int y = p.first, w = p.second;
        if (d + w < dist[y]) {
          dist[y] = d + w;
          q.push({dist[y], y});
        }
      }
    }
    return dist;
  }

  int64 call_dijkstra(const int source) {
    const vector<int64> d = dijkstra(source);
    return *max_element(d.begin(), d.end());
  }

  void main() {
    const int n = readInt(), m = readInt();
    g = vector<vector<pair<int, int>>>(n);
    for (int i = 0; i < m; i++) {
      const int x = readInt() - 1, y = readInt() - 1, w = readInt();
      g[x].emplace_back(y, w);
      g[y].emplace_back(x, w);
    }
    int64 ans = 0;
    for (int x = 0; x < n; x++) {
      ans = max(ans, call_dijkstra(x));
    }
    print(ans), pline();
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
    const int n = v.size();
    cerr << '{';
    for (int i = 0; i < n; i++) {
      _print(v[i]);
      cerr << (i != n - 1 ? ", " : "");
    }
    cerr << '}';
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
    const solution s;
  }

  const auto end = std::chrono::high_resolution_clock::now();
  const auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}