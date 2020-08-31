#include<bits/stdc++.h>
#include<fstream>

using namespace std;

int num_steps(int a) {
    if(a == 1) {
        return 1;
    }
    return 1 + num_steps(a/2);
}

int main() {
    int i = 0;
    string input_base = "input/input";
    string output_base = "output/output";
    string input_name, output_name;
    ifstream fin;
    ofstream fout;

    int n, a;
    while(i < 21) {
        if(i < 10) {
            input_name = input_base + to_string(0) + to_string(i);
            output_name = output_base + to_string(0) + to_string(i);
        } else {
            input_name = input_base + to_string(i);
            output_name = output_base + to_string(i);
        }

        input_name += ".txt";
        output_name += ".txt";
        fin.open(input_name);
        fout.open(output_name);
        fin >> n >> a;

        long long tot_steps = 1LL*n*(num_steps(a));
        if(tot_steps & 1) {
            fout << "GAURANGI";
        } else {
            fout << "RADHA";
        }
        ++i;
        fin.close();
        fout.close();
    }
    return 0;
}