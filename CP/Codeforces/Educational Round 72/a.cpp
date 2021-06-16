#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int b, p, f, h, c;
        cin >> b >> p >> f >> h >> c;
        if(b & 1) {
            --b;
        }
        int pro = 0;
        int x, y;
        for(x = 0; x <= b/2; ++x) {
            y = max(min(f, b/2 - x), 0);
            if(x > p) {
                break;
            }
            pro = max(h*x+c*y, pro);
        }
        cout << pro << '\n';
    }
    return 0;
}