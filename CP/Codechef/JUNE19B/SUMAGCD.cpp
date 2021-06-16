#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int N;
		scanf("%d", &N);
		int A[N];
		for(int i = 0; i < N; ++i)
			scanf("%d", &A[i]);

		sort(A, A + N);

		int MAX = A[N-1], MAX_2;

		if(A[0] == A[N-1])
		{
			cout << A[0] + A[N-1] << '\n';
			continue;
		}

		for(int i = 1; i <= N; ++i)
		{
			if(A[N-i] < MAX)
			{
				MAX_2 = A[N-i];
				break;
			}
		}

		int GCD = A[0];
		for(int i = 0; A[i] < MAX_2; ++i)
			GCD = __gcd(GCD, A[i]);

		int GCD_1 = __gcd(GCD, MAX_2);
		int GCD_2 = __gcd(GCD, MAX);

		(GCD_1 + MAX > GCD_2 + MAX_2) ? cout << GCD_1 + MAX << '\n': cout << GCD_2 + MAX_2 << '\n';

	}
	return 0;
}