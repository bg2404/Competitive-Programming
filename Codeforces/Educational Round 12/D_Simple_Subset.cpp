#include<bits/stdc++.h>

using namespace std;

vector<int> primes;

bool isPrime(int n) 
{
    
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

// void printPrime(int n)
// {
//     for (int i = 2; i <= n; i++) {
//         if (isPrime(i))
//             primes.push_back(i);
//     }
// }


int main() {
    // printPrime(1000001);
    int n;
    cin >> n;
    int a[n];
    int num_1 = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i] == 1) {
            num_1++;
        }
    }

    sort(a, a+n);

    int is_prime[n][n];
    memset(is_prime, -1, sizeof(is_prime));
    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            // int index = *lower_bound(primes.begin(), primes.end(), a[i]+a[j]);
            if(isPrime(a[i]+a[j])) {
                is_prime[i][j] = 1;
            } else {
                is_prime[i][j] = 0;
            }
        }
    }

    if(num_1 < 2) {
        int ans = num_1;
        int x[2] = {1, 1};
        for(int i = num_1; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                if(is_prime[i][j]) {
                    ans = 2;
                    x[0] = a[i];
                    x[1] = a[j];
                    break;
                }
            }
            if(ans > 1) {
                break;
            }
        }
        if(ans == 0) {
            ans = 1;
            x[0] = a[0];
        } else if(ans == 1) {
            for(int i = num_1; i < n; ++i) {
                if(is_prime[0][i]) {
                    ans++;
                    x[1] = a[i];
                    break;
                }
            }
        }
        cout << ans << '\n';
        for(int i = 0; i < ans; ++i) {
            cout << x[i] << ' ';
        } cout << '\n';
    } else {
        int ans = num_1;
        int x;
        for(int i = num_1; i < n; ++i) {
            if(is_prime[0][i]) {
                ans++;
                x = a[i];
                break;
            }
        }
        cout << ans << '\n';
        for(int i = 0; i < num_1; ++i) {
            cout << 1 << ' ';
        }
        if(ans > num_1) {
            cout << x;
        }
        cout << '\n';
    }
        
    return 0;
}