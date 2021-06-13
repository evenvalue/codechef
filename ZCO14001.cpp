#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, h;
  cin >> n >> h;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  int crane = 0;
  bool have_box = false;
  int command;
  while (cin >> command) {
    if (command == 0) break;
    if (command == 1 and crane != 0) crane--;
    if (command == 2 and crane != n - 1) crane++;
    if (command == 3 and not have_box and a[crane] != 0) a[crane]--, have_box = true;
    if (command == 4 and have_box and a[crane] != h) a[crane]++, have_box = false;
  }
  for (int &x : a) {
    cout << x << ' ';
  }
  cout << '\n';
}