#include<bits/stdc++.h>
#include<fstream>

using namespace std;

int main() {
    srand((unsigned) time(0));
    ofstream fout_input, fout_output;

    int i = 0;

    string input_base = "input/input";
    string input_name;

    while(i <= 20) {
        if(i < 10) {
            input_name = input_base + to_string(0) + to_string(i);
        } else {
            input_name = input_base + to_string(i);
        }

        input_name += ".txt";
        
        fout_input.open(input_name);

        int n = 1 + rand() % 1000000;
        int m = 1 + rand() % 10000000;
        int q = 1 +  rand() % 100000;
        fout_input << n << ' ' << m << ' ' << q << '\n';

        fout_input << 1 + rand()*1LL % 1000000000;
        for(int i = 1; i < n; ++i) {
            fout_input << ' ' << 1 + rand()*1LL % 1000000000;
        }
        fout_input << '\n';

        int a = 1 + rand()*1LL % 1000000000;
        int b = 1 + rand()*1LL % 1000000000;
        int c = 1 + rand()*1LL % 1000000000;
        int d = 1 + rand()*1LL % 1000000000;
        int e = 1 + rand()*1LL % 1000000000;
        int f = 1 + rand()*1LL % 1000000000;

        int l0 = 1 + rand()*1LL % n;
        int r0 = 1 + rand()*1LL % n;
        if(l0 > r0) {
            swap(l0, r0);
        }

        fout_input << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';

        fout_input << l0 << ' ' << r0 << '\n';

        fout_input << 1 + rand()*1LL % 10000000;
        for(int i = 1; i < q; ++i) {
            fout_input << ' ' << 1 + rand()*1LL % 10000000;
        }

        fout_input.close();


        ++i;
    }

    return 0;
}   