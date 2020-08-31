#include <bits/stdc++.h>
#include <string>

using namespace std;

string Lexismall(string s, int k)
{
	string sub1 = s.substr(k,s.size()-1);
	string sub2 = s.substr(0,s.length() - sub1.length());
	// cout<<sub1<<" "<<sub2<<" |"<<endl;
	return sub1+sub2;
}

int main()
{
	long long int test;
	cin>>test;
	for (long long int t = 0; t < test; ++t)
	{
		string s;
		cin>>s;
		vector<int> vect;
		char c = 'z';
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] < c)
			{
				c = s[i];
			}
		}
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == c)
			{
				vect.push_back(i);
			}
		}
		vector<string> vect2;
		int s1 = vect.size();
		cout<<s1<<endl;
		for (int i = 0; i < s1; ++i)
		{
			vect2.push_back(Lexismall(s,vect[i]));
			// cout<<vect2[i]<<endl;
		}
		string ans = vect2[0];
		for (int i = 0; i < s1; ++i)
		{	cout<<i<<" "<<ans<<" "<<vect2[i]<<" "<<(ans < vect2[i])<<" "<<endl;

			if (vect2[i]>ans)
			{
				ans = vect2[i];
				// cout<<i<<endl;
						// cout<<ans<<endl;

			}
		}
        cout << ans << '\n';

        int a[2] = {1,2}, b[3] = {1,2,3};
        char d2[] = "adf";
		if("archana" > "aarchan")
		{
			cout<<"true"<<endl;
		}


	}
	
}