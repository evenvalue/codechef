#include <algorithm>
#include <array>
#include <cmath>
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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  auto check = [&](int l, int r) {
    bool palindrome = true;
    while (l < r) {
      palindrome &= (a[l] == a[r]);
      l++, r--;
    }
    return palindrome;
  };
  vector<vector<int>> palindromes(n);
  for (int l = 0; l < n; l++) {
    for (int r = l; r < n; r++) {
      if (check(l, r)) {
        palindromes[l].push_back(r);
      }
    }
  }
  vector<int> best(n + 1, kInf);
  //best[i] is the minimum number of palindrome sequences in a[i... n - 1].
  best[n] = 0;
  for (int l = n - 1; l >= 0; l--) {
    for (const int r : palindromes[l]) {
      best[l] = min(best[l], 1 + best[r + 1]);
    }
  }
  cout << best[0] << '\n';
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