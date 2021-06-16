#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long uint64;

uint64 PowMod(uint64 x, uint64 e, uint64 mod)
{
  uint64 res;

  if (e == 0)
  {
    res = 1;
  }
  else if (e == 1)
  {
    res = x;
  }
  else
  {
    res = PowMod(x, e / 2, mod);
    res = res * res % mod;
    if (e % 2)
      res = res * x % mod;
  }

  return res;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		uint64 K;
		cin >> K;
		uint64 ans = (5 * PowMod(2, K, 1000000007)) % 1000000007;
		cout << ans << '\n';
	}
	return 0;
}