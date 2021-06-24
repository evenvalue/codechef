#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class SCC {
  const int n;
  const vector<vector<int>> g;
  vector<vector<int>> gr;
  vector<vector<int>> comp;

  void build_gr() {
    for (int x = 0; x < n; x++) {
      for (const int y : g[x]) {
        gr[y].push_back(x);
      }
    }
  }

  void build_order(const int x, vector<int> &order, vector<bool> &visit) {
    visit[x] = true;
    for (const int y : g[x]) {
      if (visit[y]) continue;
      build_order(y, order, visit);
    }
    order.push_back(x);
  }

  void build_comp(const int x, vector<bool> &visit) {
    visit[x] = true;
    for (const int y : gr[x]) {
      if (visit[y]) continue;
      build_comp(y, visit);
    }
    comp.back().push_back(x);
  }

  void kosaraju() {
    vector<int> order;
    vector<bool> visit(n, false);
    for (int x = 0; x < n; x++) {
      if (visit[x]) continue;
      build_order(x, order, visit);
    }
    visit.assign(n, false);
    while (not order.empty()) {
      const int x = order.back();
      order.pop_back();
      if (visit[x]) continue;
      comp.emplace_back();
      build_comp(x, visit);
    }
  }

public:
  explicit SCC(const vector<vector<int>> &g) : n(g.size()), g(g), gr(g.size()) {
    build_gr();
    kosaraju();
  }

  vector<vector<int>> components() {
    return comp;
  }
};

vector<vector<int>> condense(const vector<vector<int>> &g, const vector<int> &comp) {
  const int n = g.size();
  const int parts = *max_element(comp.begin(), comp.end()) + 1;
  vector<vector<int>> gc(parts);
  for (int x = 0; x < n; x++) {
    for (const int y : g[x]) {
      gc[comp[x]].push_back(comp[y]);
    }
  }
  return gc;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  vector<vector<int>> g(n);
  for (int x = 0; x < n; x++) {
    g[x].push_back((a[x] + x + 1) % n);
  }
  SCC scc(g);
  const vector<vector<int>> &strong_comp = scc.components();
  const int parts = strong_comp.size();
  vector<int> comp(n);
  for (int c = 0; c < parts; c++) {
    for (const int x : strong_comp[c]) {
      comp[x] = c;
    }
  }
  const vector<vector<int>> &gc = condense(g, comp);
  int ans = 0;
  for (int c = 0; c < parts; c++) {
    bool add = true;
    for (const int &nbr : gc[c]) {
      if (nbr == c) continue;
      add = false;
      break;
    }
    ans += (add ? (int) strong_comp[c].size() : 0);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}