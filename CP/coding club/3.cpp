#include<bits/stdc++.h>
using namespace std;
int64_t n, U;
vector<long long> E;

int binary_search(int key, int n) {
    int l = 0, r = n, m;
    while(l < r) {
        m = (l + r) / 2;
        if(E[m] > key) {
            r = m-1;
        } else if(E[m] < key){
            l = m + 1;
        } else { 
            l = m;
            break;
        }
        //cout << key << ' ' << l << ' ' << E[l] << ' ' << m << ' '<< r << ' ' << E[r] << '\n';
    }

    
    if(E[l] > key) {
        l--;
    }
    return l;
}

int main(){
    cin >> n >> U;
    int64_t input;
    for(int i = 0 ;i < n; ++i) {
        cin >> input;
        E.push_back(input);
    }
    double max_efficiency = -1;
    for(int i = 0; i < n; ++i) {
        int k = binary_search(E[i] + U, n-1);
        
        //cout << i << " " << E[i] << " " << k << " " << E[k] << ' ';
        if(k == n) {
            break;
        }

        if(k < i + 2) {
            continue;
        }

        if(E[k] > E[i] + U) {
            k--;
        }
        double efficiency = 1 - ((double)E[i+1] - E[i]) / (E[k] - E[i]);
        //cout << efficiency << '\n';
        if(efficiency > max_efficiency) {
            max_efficiency = efficiency;
        }
    }

    cout << setprecision(9) << max_efficiency << '\n';

    return 0;
}