#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if(n % 2) {
		cout << 0 << '\n';
	} else {
		long long ans = 1;
		for(int i = 0; 2 * i < n; ++i)
			ans *= 2;
		cout << ans << '\n';
	}
	return 0;
}