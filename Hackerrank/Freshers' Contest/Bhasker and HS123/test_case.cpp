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

        ++i;
        
        fout_input.open(input_name);

        int n = 1 + (rand()*2LL % 1000000);
        int a = 1 + (rand()*2LL % 1000000000);
        fout_input << n << " " << a;
        fout_input.close();
    }

    return 0;
}