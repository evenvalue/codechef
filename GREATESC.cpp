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
#include <queue>
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

vector<int> bfs(const vector<vector<int>> &g, const int s = 0) {
  const int n = g.size();
  vector<int> d(n, kInf);
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (not q.empty()) {
    const int x = q.front();
    q.pop();
    for (const int y : g[x]) {
      if (d[y] != kInf) continue;
      d[y] = d[x] + 1;
      q.push(y);
    }
  }
  return d;
}

void solve(const int TestCase) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int s, t;
  cin >> s >> t;
  vector<int> d = bfs(g, s - 1);
  cout << (d[t - 1] == kInf ? 0 : d[t - 1]) << '\n';
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