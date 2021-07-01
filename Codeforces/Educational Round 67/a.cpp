#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, s, t;
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> s >> t;
		cout << max(s,t) - (s+t-n) + 1 << '\n';
	}
	return 0;
}