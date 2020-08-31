#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

typedef complex<double> cd; 

template<typename T>
void printVec(vector<T> v) {
    int n = v.size();
    for(int i = 0; i < n; ++i) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

template<typename T>
void printArr(T arr[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
} 

vector<cd> fft(vector<cd>& a) 
{ 
    int n = a.size(); 
  
    // if input contains just one element 
    if (n == 1) 
        return vector<cd>(1, a[0]); 
  
    // For storing n complex nth roots of unity 
    vector<cd> w(n); 
    for (int i = 0; i < n; i++) { 
        double alpha = 2 * M_PI * i / n; 
        w[i] = cd(cos(alpha), sin(alpha)); 
    } 
  
    vector<cd> A0(n / 2), A1(n / 2); 
    for (int i = 0; i < n / 2; i++) { 
  
        // even indexed coefficients 
        A0[i] = a[i * 2]; 
  
        // odd indexed coefficients 
        A1[i] = a[i * 2 + 1]; 
    } 
  
    // Recursive call for even indexed coefficients 
    vector<cd> y0 = fft(A0);  
  
    // Recursive call for odd indexed coefficients 
    vector<cd> y1 = fft(A1); 
  
    // for storing values of y0, y1, y2, ..., yn-1. 
    vector<cd> y(n); 
  
    for (int k = 0; k < n / 2; k++) { 
        y[k] = y0[k] + w[k] * y1[k]; 
        y[k + n / 2] = y0[k] - w[k] * y1[k]; 
    } 
    return y; 
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc) {
        // cout << "Case #" << tc << ": \n";
        int n, m, p;
        fastscan(n);
        fastscan(m);
        fastscan(p);
        
        int a[n], b[m];

        for(int i = 0; i < n; ++i) {
            fastscan(a[i]);
        }

        for(int i = 0; i < m; ++i) {
            fastscan(b[i]);
        }


    }
    return 0;
}