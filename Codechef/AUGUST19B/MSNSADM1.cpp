#include<bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  while(T--) {
    int N;
    cin >> N;
    vector<int> points, A, B;
    int input;
    for(int i = 0; i < N; ++i) {
      cin >> input;
      A.push_back(input);
    }
    for(int i = 0; i < N; ++i) {
      cin >> input;
      B.push_back(input);
    }
    for(int i = 0; i < N; ++i) {
      points.push_back(max(0, A[i]*20 - B[i]*10));
    }
    cout << *max_element(points.begin(), points.end()) << '\n';
  }
}
