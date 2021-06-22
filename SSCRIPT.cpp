#include <iostream>
#include <string>
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
    int cnt = 0;
    bool ans = false;
    for (const char c : s) {
      cnt = (c == '*' ? cnt + 1 : 0);
      ans |= (cnt >= k);
    }
    cout << (ans ? "YES" : "NO") << '\n';
  }
}