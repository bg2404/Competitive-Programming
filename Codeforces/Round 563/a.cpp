#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	n *= 2;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a + n);

	if(a[0] == a[n - 1])
		cout << -1 << '\n';
	else
		for(int i = 0; i < n; ++i)
			cout << a[i] << ' ';
	return 0;
}