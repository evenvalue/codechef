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
const int kMod = 1e4;

ifstream fin("input.txt");
ofstream fout("output.txt");

void solve(const int TestCase) {
  int n;
  cin >> n;
  vector<int> f(n + 3), g(n + 3);
  f[0] = 1, g[0] = 0;
  f[1] = 1, g[1] = 1;
  for (int i = 2; i <= n; i++) {
    f[i] = (f[i - 1] + f[i - 2] + 2 * g[i - 2]) % kMod;
    g[i] = (f[i - 1] + g[i - 1]) % kMod;
  }
  cout << f[n] << '\n';
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