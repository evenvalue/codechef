#include <algorithm>
#include <array>
#include <cassert>
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

struct participant {
  int cobol;
  int vault;
  int donut;

  bool operator<(const participant &other) const {
    return vault + donut > other.vault + other.donut;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<participant> participants(n);
  for (participant &p : participants) {
    cin >> p.cobol >> p.vault >> p.donut;
  }
  sort(participants.begin(), participants.end());
  int64 wait = 0, ans = 0;
  for (const participant &p : participants) {
    ans = max(ans, wait + p.cobol + p.vault + p.donut);
    wait += p.cobol;
  }
  cout << ans << '\n';
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