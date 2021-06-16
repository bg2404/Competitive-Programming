#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        double k[N], k_inverse[N];
        double c[N];
        for(int i = 0; i < N; ++i) {
            cin >> k[i];
            k_inverse[i] = 1 / k[i];
        }
        for(int i = 0; i < N; ++i) {
            cin >> c[i];
        }

        double sum_k_inverse = 0, sum_k_c = 0, p;
        for(int i = 0; i < N; ++i) {
            sum_k_c += k[i]*c[i];
            sum_k_inverse += k_inverse[i];
        }
        p = sum_k_c / sum_k_inverse;
        if(p < 0) {
            cout << "-1";
        } else {
            double F = sqrt(p) * sum_k_inverse;
            cout << F << ' ';
            for(int i = 0; i < N; ++i) {
                double x = p / (k[i]*k[i]) - c[i];
                cout << x << ' ';
            }
        }
        cout << endl; 
    }
    return 0;
}