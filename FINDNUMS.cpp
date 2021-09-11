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

bool rec(const int s, const int p, const int k, const vector<int> &factors, vector<int> &ans) {
  if (k == 0) {
    return (s == 0 and p == 1);
  }
  for (const int factor : factors) {
    if (p % factor) continue;
    if (not rec(s - factor, p / factor, k - 1, factors, ans)) continue;
    ans.push_back(factor);
    return true;
  }
  return false;
}

void solve(const int TestCase) {
  int s, p, k;
  cin >> s >> p >> k;
  vector<int> factors;
  for (int f = 1; f <= p; f++) {
    if (p % f) continue;
    factors.push_back(f);
  }
  vector<int> ans;
  if (rec(s, p, k, factors, ans)) {
    for (const int x : ans) {
      cout << x << ' ';
    }
  } else {
    cout << "NO";
  }
  cout << '\n';
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