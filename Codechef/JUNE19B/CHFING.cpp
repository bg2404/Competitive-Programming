#include<bits/stdc++.h>
using namespace std;

const uint64_t MOD = 1000000007;

int main()
{
	uint64_t T;
	cin >> T;

	while(T--)
	{
		int64_t N, K;
		cin >> N >> K;
		int64_t X = (K - 1) / (N - 1) + 1;
		int64_t sum = ( (X % MOD) * ((K - 1) % MOD) ) % MOD;
		int64_t A;
		if(X % 2)
		{
			A = ((((((X - 1)/2)%MOD) * (X%MOD))%MOD) * ((N-1)%MOD))%MOD;
		}
		else
		{
			A = ((((((X)/2)%MOD) * ((X-1)%MOD))%MOD) * ((N-1)%MOD))%MOD;
		}
		//uint64_t sum = (((X%MOD)*((K+N-2)%MOD))%MOD - (((((X%MOD)*((X+1)%MOD)%MOD)*((N-1)%MOD))%MOD)/2)%MOD) % MOD;
		sum = (sum - A) % MOD;
		cout << sum % MOD << '\n';
	}
	return 0;
}