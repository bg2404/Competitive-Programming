#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main () {
    int T;
    cin >> T;
    while(T--) {
        int A, B;
        cin >> A >> B;
        int count = 0;
        int digits = 0;
        int temp = 1;
        while(temp <= B) {
            temp *= 10;
            ++digits;
        }
        count += (digits-1) * A;
        if(B == pow(10,digits)-1) {
            count += A;
        }        
        cout << count << '\n';
    }
    return 0;
}