#include<iostream>

using namespace std;

int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	long long t = 2*c;
	t += 2*min(a,b);
	if(a!=b)	t += 1;
	cout << t << '\n';
	return 0;
}