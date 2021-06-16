#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;

	int upvote = x - y;
	int all_upvote = upvote + z;
	int all_downvote = upvote - z;

	if(all_downvote > 0 && all_upvote > 0)
		cout << '+' << '\n';
	else if(all_downvote < 0 && all_upvote < 0)
		cout << '-' << '\n';
	else if(all_upvote == 0 && all_downvote == 0)
		cout << '0' << '\n';
	else
		cout << '?' << '\n';
	return 0;
}