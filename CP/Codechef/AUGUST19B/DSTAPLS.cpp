#include<bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    long long N, K;
    cin >> N >> K;
    long long M = N / K;
    if(M % K) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
