#include<bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--)
	{
		int D;
		cin >> D;
		char S[D];
		int P = 0, req_P;
		for(int i = 0; i < D; ++i)
		{
			cin >> S[i];
			if(S[i] == 'P') ++P;
		}
		req_P = 3*D/4 - P;
		if(D % 4) ++req_P;

		if(req_P < 0)
		{
			req_P = 0;
			cout << req_P << '\n';
			continue;
		}

		int proxy = 0;
		bool prev = false, next = false;
		for(int i = 2; i < D - 2; ++i)
		{
			if(S[i] == 'A')
			{
				if(S[i-1] == 'P' || S[i-2] == 'P') prev = true;
				if(S[i+1] == 'P' || S[i+2] == 'P') next = true;

				if(prev && next) ++proxy;
			}
			prev = next = false;
		}

		if(proxy < req_P) cout << -1 << '\n';
		else cout << req_P << '\n';
	}
	return 0;
}