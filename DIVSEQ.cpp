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
const int kMod = 1e9 + 7;

ifstream fin("input.txt");
ofstream fout("output.txt");

void solve(const int TestCase) {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  a[0] = 1;
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<int> best(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[i] % a[j]) continue;
      best[i] = max(best[i], best[j] + 1);
    }
  }
  cout << *max_element(best.begin(), best.end()) << '\n';
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