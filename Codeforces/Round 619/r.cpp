#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int l;cin>>l;
	string s;cin>>s;
	ll int n=s.length();
	if(n%l!=0)
	{
		n=1+(n-1)/l;
		string t(l,'0');
		t[0]='1';
		while(n--)cout<<t;
	}	
	else 
	{
		
		string t=s.substr(0,l);
		string r;
		for(int i=0;i<n;i=i+l)
		{
			r=r+t;
		}
		if(r<=s)
		{
			for(int i=l-1;i>=0;i--)
			{
				if(t[i]=='9')
				{
					t[i]='0';
				}
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
			for(int i=0;i<n;i=i+l)
			{
				r+=t;
			}
		}
		cout<<r;
	}
	cout<<"\n";
}