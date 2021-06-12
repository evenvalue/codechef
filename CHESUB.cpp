#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int64 int64_t

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }
    vector<vector<int64>> best(k + 1, vector<int64>(n, -1e15));
    vector<vector<int64>> pref(k + 1, vector<int64>(n, -1e15));
    fill(best[0].begin(), best[0].end(), 0);
    fill(pref[0].begin(), pref[0].end(), 0);
    best[1][0] = pref[1][0] = a[0];
    for (int j = 1; j <= k; j++) {
      for (int i = 1; i < n; i++) {
        best[j][i] = max(pref[j - 1][i - 1], best[j][i - 1]) + (j * a[i]);
        pref[j][i] = max(pref[j][i - 1], best[j][i]);
      }
    }
    cout << *max_element(best[k].begin(), best[k].end()) << '\n';
  }
}