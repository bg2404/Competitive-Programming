#include<bits/stdc++.h>

using namespace std;

int digit_sum(int A) {
    int res = 0;
    while(A) {
        res += A % 10;
        A /= 10;
    }
    return res;
}

void solve() {
    int N;
    cin >> N;
    int chef = 0, morty = 0;
    for(int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        if(digit_sum(A) > digit_sum(B)) {
            ++chef;
        } else if(digit_sum(A) < digit_sum(B)) {
            ++morty;
        } else {
            ++chef;
            ++morty;
        }
    }
    if(chef > morty) {
        cout << "0 " << chef << '\n';
    } else if(chef < morty) {
        cout << "1 " << morty << '\n';
    } else {
        cout << "2 " << chef << '\n';
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}