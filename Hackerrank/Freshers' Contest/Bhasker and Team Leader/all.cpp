#include<bits/stdc++.h>
#include<stdlib.h>

using namespace std;

int main() {
    srand((unsigned) time(0));
    ofstream fout_input, fout_output;

    int i = 0;

    string input_base = "input/input", output_base = "output/output";
    string input_name, output_name;

    while(i <= 20) {
        if(i < 10) {
            input_name = input_base + to_string(0) + to_string(i);
            output_name = output_base + to_string(0) + to_string(i);
        } else {
            input_name = input_base + to_string(i);
            output_name = output_base + to_string(i);
        }

        input_name += ".txt";
        output_name += ".txt";
        string s = "./solution < " + input_name + " > " + output_name;

        cout << s << '\n';
        
        system(s.c_str());


        ++i;
    }

    return 0;
}   