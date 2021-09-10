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

bool punctuation(const char c) {
  return (c == '\'' or c == '.' or c == ',' or c == ';' or c == ':' or c == ' ' or c == '\n');
}

void solve(const int TestCase) {
  int lines;
  cin >> lines;
  vector<string> st;
  for (int i = 0; i <= lines; i++) {
    string line;
    getline(cin, line);
    string add;
    for (const char c : line) {
      if (punctuation(c)) {
        st.push_back(add);
        add.clear();
      } else {
        add += c;
      }
    }
  }
  reverse(st.begin(), st.end());
  for (const string &s : st) {
    if (s.empty()) continue;
    cout << s << ' ';
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