#include <iostream>
#include <vector>
using namespace std;

#define int64 int64_t

vector<int> sieve(const int n) {
  vector<int> primes(n + 1, 1);
  primes[0] = primes[1] = 0;
  for (int64 i = 2; i <= n; i++) {
    if (not primes[i]) continue;
    for (int64 j = i * i; j <= n; j += i) {
      primes[j] = 0;
    }
  }
  for (int i = 3; i <= n; i++) {
    primes[i] += primes[i - 1];
  }
  return primes;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> primes = sieve(1e7 + 5);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (n > 3) + primes[n] - primes[n / 2] << '\n';
  }
}