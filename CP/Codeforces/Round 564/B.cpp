#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = n / 2 + 1;
	cout << ans << '\n';
	int row = 1, col = 1;
	for(int i = 0; i < n; ++i)
	{
		cout << row << ' ' << col << '\n';
		if(i%2) row++;
		else col++;
	}
	return 0;
}