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
  string s;
  cin >> n >> s;
  vector<vector<bool>> palindrome(n, vector<bool>(n, true));
  for (int len = 2; len <= n; len++) {
    for (int l = 0; l <= n - len; l++) {
      const int r = l + len - 1;
      palindrome[l][r] = (s[l] == s[r]) and palindrome[l + 1][r - 1];
    }
  }
  for (int len = n; len > 0; len--) {
    for (int l = 0; l <= n - len; l++) {
      const int r = l + len - 1;
      if (palindrome[l][r]) {
        cout << len << '\n';
        cout << s.substr(l, len) << '\n';
        return;
      }
    }
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