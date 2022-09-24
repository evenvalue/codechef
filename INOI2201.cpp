#include <bits/stdc++.h>
using namespace std;

#ifdef evenvalue
  #include "debug.h"
  #define debug(...) print(#__VA_ARGS__, __VA_ARGS__)
#else
  #define debug(...)
#endif

using int64 = long long;
using ld = long double;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;

namespace read {
int Int() {
  int x;
  cin >> x;
  return x;
}
int64 Int64() {
  int64 x;
  cin >> x;
  return x;
}
char Char() {
  char c;
  cin >> c;
  return c;
}
string String() {
  string s;
  cin >> s;
  return s;
}
double Double() {
  return stod(String());
}
ld LongDouble() {
  return stold(String());
}
template<typename T1, typename T2>
pair<T1, T2> Pair() {
  pair<T1, T2> p;
  cin >> p.first >> p.second;
  return p;
}
template<typename T>
vector<T> Vec(const int n) {
  vector<T> v(n);
  for (T &x : v) {
    cin >> x;
  }
  return v;
}
template<typename T>
vector<vector<T>> VecVec(const int n, const int m) {
  vector<vector<T>> v(n);
  for (vector<T> &vec : v) {
    vec = Vec<T>(m);
  }
  return v;
}
}//namespace read

constexpr int kInf = 1e9 + 10;
constexpr int64 kInf64 = 5e13;
constexpr int kMod = 1e9 + 7;

struct office {
  int x = -kInf;
  int s = 0;
  int e = 0;

  bool operator<(const office &other) const {
    return x < other.x;
  }
};

int dist(const int x1, const int x2) {
  return abs(x1 - x2);
}

inline void solution() {
  const int n = read::Int(); //number of houses
  const int m = read::Int(); //number of offices
  vector<int> houses(n + 1);
  for (int i = 1; i <= n; i++) {
    houses[i] = read::Int();
  }
  vector<office> offices(m + 1);
  for (int i = 1; i <= m; i++) {
    auto &[x, s, e] = offices[i];
    x = read::Int();
    s = read::Int();
    e = read::Int();
  }

  sort(houses.begin(), houses.end());
  sort(offices.begin(), offices.end());

  vector<vector<int64>> dp(m + 1, vector<int64>(n + 1, kInf64));
  dp[0][0] = 0;
  for (int i = 1; i <= m; i++) {
    const auto &[x, s, e] = offices[i];
    vector<int64> pdist(n + 1);
    for (int j = 1; j <= n; j++) {
      pdist[j] = pdist[j - 1] + dist(x, houses[j]);
    }

    deque<pair<int64, int>> d;

    auto push = [&](const int j) {
      const int64 c = dp[i - 1][j] - pdist[j];
      while (not d.empty() and d.back().first >= c) {
        d.pop_back();
      }
      d.emplace_back(c, j);
    };

    for (int j = s; j <= n; j++) {
      push(j - s);
      if (d.front().second == j - e - 1) {
        d.pop_front();
      }
      dp[i][j] = pdist[j] + d.front().first;
    }
  }

  cout << (dp[m][n] >= kInf64 ? -1 : dp[m][n]) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  cout << fixed << setprecision(10);

  int testcases = 1;
  //cin >> testcases;
  while (testcases--) {
    solution();
  }
}