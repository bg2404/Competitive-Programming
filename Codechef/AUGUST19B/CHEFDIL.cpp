#include<bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  while(T--) {
    string S;
    cin >> S;
    int sum = 0;
    for(int i = 0; i < S.size(); ++i) {
      sum = sum + (S[i] - '0');
    }
    if(sum & 1) {
      cout << "WIN\n";
    } else {
      cout << "LOSE\n";
    }
  }
  return 0;
}
