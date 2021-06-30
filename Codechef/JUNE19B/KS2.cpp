#include <bits/stdc++.h>

using namespace std;

unsigned long long sum_of_digits(unsigned long long N)
{
	if(N < 10)
		return N;

	return N % 10 + sum_of_digits(N / 10);
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		unsigned long long N;
		cin >> N;

		int rem = sum_of_digits(N) % 10;
		int unit_digit = (rem) ? (10 - rem): rem;
		unsigned long long req_num =  N * 10 + unit_digit;
		cout << req_num << '\n';
	}
	return 0;
}