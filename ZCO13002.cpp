#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <fstream>
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

ifstream fin("input.txt");
ofstream fout("output.txt");

struct charm {
  int x, y;
  int k;
};

bool charmed(const pair<int, int> &p, const charm &c) {
  return ((abs(p.first - c.x) + abs(p.second - c.y)) <= c.k);
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> berry(n + 1, vector<int>(n + 1));
  for (int r = 1; r <= n; r++) {
    for (int c = 1; c <= n; c++) {
      cin >> berry[r][c];
    }
  }
  vector<charm> charms(m);
  for (charm &c : charms) {
    cin >> c.x >> c.y >> c.k;
  }
  vector<vector<bool>> safe(n + 1, vector<bool>(n + 1, false));
  for (const charm &ch : charms) {
    for (int r = max(1, ch.x - ch.k); r <= min(n, ch.x + ch.k); r++) {
      const int left = ch.k - abs(ch.x - r);
      for (int c = max(1, ch.y - left); c <= min(n, ch.y + left); c++) {
        safe[r][c] = true;
      }
    }
  }
  vector<vector<int>> best(n + 1, vector<int>(n + 1, -kInf));
  best[0][1] = best[1][0] = 0;
  for (int r = 1; r <= n; r++) {
    for (int c = 1; c <= n; c++) {
      if (not safe[r][c] or max(best[r - 1][c], best[r][c - 1]) == -kInf) continue;
      best[r][c] = max(best[r - 1][c], best[r][c - 1]) + berry[r][c];
    }
  }
  if (best[n][n] == -kInf) {
    cout << "NO";
  } else {
    cout << "YES\n";
    cout << best[n][n];
  }
  cout << '\n';
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