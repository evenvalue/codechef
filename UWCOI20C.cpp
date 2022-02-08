#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using int64 = int64_t;
using ld = long double;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;

int readInt() {
  int x;
  cin >> x;
  return x;
}
int64 readInt64() {
  int64 x;
  cin >> x;
  return x;
}
char readChar() {
  char c;
  cin >> c;
  return c;
}
string readString() {
  string s;
  cin >> s;
  return s;
}
double readDouble() {
  return stod(readString());
}
ld readLongDouble() {
  return stold(readString());
}
template<typename T1, typename T2>
pair<T1, T2> readPair() {
  pair<T1, T2> p;
  cin >> p.first >> p.second;
  return p;
}
template<typename T>
vector<T> readVec(const int sz) {
  vector<T> v(sz);
  for (T &x : v) {
    cin >> x;
  }
  return v;
}
template<typename T>
vector<vector<T>> readVecVec(const int n, const int m) {
  vector<vector<T>> a(n);
  for (vector<T> &v : a) {
    v = readVec<T>(m);
  }
  return a;
}

const int kInf = 1e9 + 10;

class dsu {
  const int n;
  vector<int> e;

  int pfind(const int x) {
    return (e[x] < 0 ? x : pfind(e[x]));
  }

public:
  explicit dsu(const int n) : n(n), e(n, -1) {}

  int find(const int x) {
    assert(0 <= x and x < n);
    return pfind(x);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y];
    e[y] = x;
    return true;
  }

  size_t size(const int x) {
    return -e[find(x)];
  }
};

struct point {
  int x, y;

  bool operator<(const point &other) const {
    return x < other.x;
  }
};

struct query {
  int x, y, p;
  int i;

  bool operator<(const query &other) const {
    return p < other.p;
  }
};

void solution() {
  const int n = readInt() + 2, m = readInt() + 2, qry = readInt();
  vector<vector<int>> grid(n, vector<int>(m, kInf));

  auto hash = [&](const int r, const int c) {
    return r * m + c;
  };

  vector<pair<int, point>> order(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (0 < i and i < n - 1 and 0 < j and j < m - 1) {
        grid[i][j] = readInt();
      }
      order[hash(i, j)] = {grid[i][j], point({i, j})};
    }
  }
  sort(order.begin(), order.end());

  vector<query> queries(qry);
  for (int i = 0; i < qry; i++) {
    query &q = queries[i];
    q.x = readInt(), q.y = readInt(), q.p = readInt();
    q.i = i;
  }

  sort(queries.begin(), queries.end());

  vector<pair<int, int>> nbr = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
  vector<int> ans(qry);
  dsu d(n * m);
  for (int i = 0, j = 0; j < qry; j++) {
    query &q = queries[j];
    if (q.p <= grid[q.x][q.y]) {
      ans[q.i] = 0;
      continue;
    }
    while (order[i].first < q.p) {
      const int v = order[i].first;
      const auto &[x, y] = order[i].second;
      for (const auto &[dx, dy] : nbr) {
        if (v < grid[x + dx][y + dy]) continue;
        d.unite(hash(x, y), hash(x + dx, y + dy));
      }
      i++;
    }
    ans[q.i] = d.size(hash(q.x, q.y));
  }

  for (const int x : ans) {
    cout << x << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solution();
  }
}