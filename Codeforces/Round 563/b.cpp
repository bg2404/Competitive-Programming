#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	bool all_o = true;
	bool all_e = true;
	std::vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		if(a[i] % 2)
			all_e = false;
		else
			all_o = false;
	}

	if(!(all_o || all_e))
		sort(a.begin(), a.end());

	for(int i = 0; i < n; ++i) cout << a[i] << ' ';
	return 0;
}