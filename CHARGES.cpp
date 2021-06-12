#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int ans = 0;
    for (int i = 1; i < n; i++) {
      ans += (s[i] == s[i - 1] ? 2 : 1);
    }
    while (k--) {
      int p;
      cin >> p;
      p--;
      if (p != 0) ans += (s[p] == s[p - 1] ? -1 : 1);
      if (p != n - 1) ans += (s[p + 1] == s[p] ? -1 : 1);
      s[p] = (s[p] == '0' ? '1' : '0');
      cout << ans << '\n';
    }
  }
}