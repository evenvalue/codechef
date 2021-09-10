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

void print_vector(const vector<int> &a) {
  for (const int x : a) cout << x << ' ';
  cout << '\n';
}

void solve(const int TestCase) {
  int n;
  cin >> n;
  vector<vector<int>> v(n);
  for (vector<int> &a : v) {
    int x;
    while (cin >> x) {
      if (x == -1) break;
      a.push_back(x);
    }
  }
  sort(v.begin(), v.end(), [](const vector<int> &x, const vector<int> &y) {
    const int n = x.size(), m = y.size();
    for (int i = 0; i < min(n, m); i++) {
      if (x[i] != y[i]) {
        return x[i] < y[i];
      }
    }
    return n < m;
  });
  for (const vector<int> &a : v) {
    print_vector(a);
  }
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