#include <bits/stdc++.h> 
using namespace std; 

bool prime[100001];

void SieveOfEratosthenes(int n) 
{ 
	for(int i = 0; i <= n; ++i)
	{
		prime[i] = true;
	}

	for (int p=2; p*p<=n; p++) 
	{ 
		if (prime[p] == true) 
		{ 
			for (int i=p*p; i<=n; i += p) 
				prime[i] = false; 
		} 
	}
} 

int main() 
{ 
	int n;
	cin >> n; 
	SieveOfEratosthenes(n); 
	int counter = 0;
	int list[n+1];
	memset(list, 0, sizeof(list));
	for(int i = 2; i <= n; ++i)
	{
		if(prime[i])
		{
			list[i] = ++counter;
			for(int j = i*i; j <=n; ++j)
			{
				if(list[j] == 0)
					list[j] = counter;
			}
		}
	}

	for(int i = 2; i <= n; ++i)
		cout << list[i] << ' ';
	return 0; 
} 
