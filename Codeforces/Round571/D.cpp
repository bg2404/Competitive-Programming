#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	double a[n];
	int b[n];
	long long sum = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = floor(a[i]);
		sum += b[i];
	}
	int i = 0;
	while(sum < 0) {
		if(a[i] - b[i]) {
			b[i]++;
			sum++;
		}
		i++;
	}

	for(int i = 0; i < n; ++i) {
		cout << b[i] << '\n';
	}


	return 0;
}