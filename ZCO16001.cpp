#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
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

void solve() {
  int n, k;
  cin >> n >> k;
  auto best = [&](multiset<int> first, multiset<int> second) -> int {
    for (int swaps = 0; swaps < k and (*first.begin() < *second.rbegin()); swaps++) {
      const int x = (*first.begin());
      const int y = (*second.rbegin());
      first.erase(first.begin()), first.insert(y);
      second.erase(prev(second.end())), second.insert(x);
    }
    return *first.rbegin() + *second.rbegin();
  };
  vector<int> books(2 * n);
  for (int &book : books) cin >> book;
  multiset<int> shelf1(books.begin(), books.begin() + n);
  multiset<int> shelf2(books.begin() + n, books.end());
  cout << min(best(shelf1, shelf2), best(shelf2, shelf1)) << '\n';
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