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

void solve() {
  int n;
  cin >> n;
  int p1 = 0, p2 = 0;
  vector<pair<int, bool>> leads(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    p1 += x, p2 += y;
    leads[i].first = abs(p1 - p2);
    leads[i].second = ((p2 >= p1));
  }
  sort(leads.rbegin(), leads.rend());
  cout << (int)leads[0].second + 1 << ' ' << leads[0].first << '\n';
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