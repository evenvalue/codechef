#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
using int64 = int64_t;

const int64 kInfL = 1e15 + 10;
const int kInf = 1e9 + 10;
const int kMod = 1e9 + 7;

pair<vector<int>, vector<int64>> dijkstra(const vector<vector<pair<int, int>>> &g, const int s = 0) {
  const int n = g.size();
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
  vector<int64> d(n, kInfL);
  vector<int> p(n, -1);
  d[s] = 0;
  q.push({0, s});
  while (not q.empty()) {
    const int64 dx = q.top().first;
    const int x = q.top().second;
    q.pop();
    if (dx != d[x]) continue;
    for (const pair<int, int> edge : g[x]) {
      const int w = edge.first, y = edge.second;
      if (dx + w >= d[y]) continue;
      d[y] = dx + w;
      p[y] = x;
      q.push({d[y], y});
    }
  }
  return {p, d};
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    x--, y--;
    g[x].emplace_back(w, y);
    g[y].emplace_back(w, x);
  }
  int64 dist = 0;
  for (int s = 0; s < n; s++) {
    const vector<int64> d = dijkstra(g, s).second;
    for (const int64 len : d) {
      if (len == kInfL) continue;
      dist = max(dist, len);
    }
  }
  cout << dist << '\n';
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