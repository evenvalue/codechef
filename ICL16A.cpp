#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int weight(const string &s1, const string &s2) {
  const int m = s1.size();
  int res = 0;
  for (int i = 0; i < m; i++) {
    res = max(res, abs(s1[i] - s2[i]));
  }
  return res;
}

class dsu {
  vector<int> e;

public:
  explicit dsu(int n) : e(n, -1) {}

  int find(const int x) {
    return e[x] < 0 ? x : (e[x] = find(e[x]));
  }

  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y];
    e[y] = x;
    return true;
  }
};

struct edge {
  int w;
  int x;
  int y;

  bool operator<(const edge other) const {
    return w < other.w;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> rows(n);
  for (string &row : rows) {
    cin >> row;
  }
  vector<edge> edges;
  for (int x = 0; x < n; x++) {
    for (int y = x + 1; y < n; y++) {
      const int w = weight(rows[x], rows[y]);
      edges.push_back({w, x, y});
    }
  }
  sort(edges.begin(), edges.end());
  int ans = 0;
  dsu kruskal(n);
  for (edge &e : edges) {
    if (kruskal.find(e.x) != kruskal.find(e.y)) {
      kruskal.unite(e.x, e.y);
      ans = e.w;
    }
  }
  cout << ans << "\n";
}
