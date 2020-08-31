#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("a.cpp");
    ofstream fout("output.txt");
    string s;
    while(fin.good()) {
        getline(fin, s);
        s = "\"" + s + "\",";
        fout << s << endl;
    }
    fin.close();
    fout.close();
    return 0;
}