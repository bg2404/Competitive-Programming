#include<bits/stdc++.h>

using namespace std;

void add(int arr[], int N, int lo, int hi, int val)
{
    arr[lo] += val;
    if (hi != N)
       arr[hi + 1] -= val;
}

void updateArray(int arr[], int N)
{
    for (int i = 1; i <= N; i++)
        arr[i] += arr[i - 1];
}

void printArr(int arr[], int N) 
{
    for (int i = 0; i < N; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    int R[N+1], C[N+1], H[N+1];
    memset(R, 0, sizeof(R));
    C[0] = H[0] = 0;
    for(int i = 1; i <= N; ++i) {
      cin >> C[i];
      add(R, N, max(1, i - C[i]), min(N, i + C[i]), 1);
    }
    updateArray(R, N);
    sort(R, R + N + 1);
    for(int i = 1; i <= N; ++i) {
      cin >> H[i];
    }
    sort(H, H + N + 1);

    if(equal(R, R + N + 1, H)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
