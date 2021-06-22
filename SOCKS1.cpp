#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;
  cout << (a == b or a == c or b == c ? "YES" : "NO") << '\n';
}