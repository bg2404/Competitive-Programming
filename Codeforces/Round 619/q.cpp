//https://codeforces.com/contest/1219/problem/C
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int l;
    lli n; string s;
	cin>>l>>s;  n=s.length();
	if(n%l!=0)
	{
		n=1+(n-1)/l;
		string t(l,'0');
		t[0]='1';
		while(n--)cout<<t;
		cout<<endl;
	}
	else{
	string t=s.substr(0,l);
	string r;
	for(lli i=1;i<=n;i+=l)r+=t;
	if(r<=s)
	{
		for(lli i=l-1;i>=0;--i)
		{
			if(t[i]=='9')t[i]='0';
			else
			{
				t[i]++;
				break;
			}
		}
		if(t[0]=='0')
		{
			t[0]='1';
			n+=l;
		}
		r="";
		for(lli i=1;i<=n;i+=l)r+=t;
	}
	cout<<r<<endl;
	}
	return 0;
}