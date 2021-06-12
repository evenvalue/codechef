#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class dsu {
  vector<int> e;

  int find(const int x) {
    return e[x] < 0 ? x : (e[x] = find(e[x]));
  }

public:
  explicit dsu(const int n) : e(n, -1) {}

  int unite(int x, int y) {
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
  int x;
  int y;
  int w;

  bool operator<(const edge &other) const {
    return w < other.w;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> w(n);
    for (int &x : w) {
      cin >> x;
    }
    dsu kruskal(n);
    const int elec = distance(s.begin(), find(s.begin(), s.end(), '1'));
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        kruskal.unite(elec, i);
      }
    }
    vector<edge> edges;
    for (int i = 1; i < n; i++) {
      edges.push_back({i - 1, i, w[i] - w[i - 1]});
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (const edge &e : edges) {
      if (kruskal.unite(e.x, e.y)) {
        ans += e.w;
      }
    }
    cout << ans << "\n";
  }
}
