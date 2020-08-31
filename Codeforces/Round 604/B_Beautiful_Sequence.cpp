#include<bits/stdc++.h>

using namespace std;


vector<int> get_vector(int option, int a, int b, int a_n) {
    vector<int> ret;
    if(option == -1) {
        return ret;
    }
    if(a_n == 0) {
        if(option == 3) {
            ret.push_back(b);
        }
        return ret;
    }
    if(option > 1) {
        ret.push_back(b);
        option-=2;
    }
    if(a_n == 0) {
        return ret;
    }
    for(int i = 1; i < a_n; ++i) {
        ret.push_back(a);
        ret.push_back(b);
    }
    ret.push_back(a);
    if(option) {
        ret.push_back(b);
    }
    return ret;
}

int get_used(int option, int n) {
    if(option == 0) {
        return n-1;
    }
    if(option == 3) {
        return n+1;
    }
    return n;
}

int get_option(int a, int b) {
    if(a == b) {
        return 1;
    }
    if(a == b + 1) {
        return 0;
    }
    if(b == a + 1) {
        return 3;
    }
    return -1;
}

void print(vector<int> a) {
    for(int i = 0; i < a.size(); ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool pos = false;
    vector<int> sol;

    int a_ = a;
    for(int i = 0; i < 4 && !pos; ++i) {
        int b_ = get_used(i, a_);
        if(b >= b_ && b_ >= 0) {
            vector<int> temp_a;
            b_ = b - b_;
            temp_a = get_vector(i, 0, 1, a_);
            // cout << 'a';
            // print(temp_a);
            for(int j = 0; j < 4 && !pos; ++j) {
                int c_ = get_used(j, b_);
                // cout << "j b_ c_ = " << j << " " << b_ << " " << c_ << '\n';
                vector<int> temp, temp_b = temp_a;
                if(c >= c_ && c_ >= 0) {
                    c_ = c - c_;
                    temp = get_vector(j, 1, 2, b_);
                    // cout << 'b';
                    // print(temp);

                    if(temp.size() > 0) {
                        if(temp_a.size() > 0) {
                            if(abs(temp_a[temp_a.size()-1] - temp[0]) != 1) {
                                continue;
                            }
                        }
                        temp_b.insert(temp_b.end(), temp.begin(), temp.end());
                    }

                    // cout << "ab";
                    // print(temp_b);
                    
                    vector<int> temp_c;
                    int option = get_option(c_, d);
                    if(option == -1) {
                        continue;
                    }
                    
                    bool conti = false;
                    for(int k = option; k >= 0; ++k) {
                        temp = get_vector(k, 2, 3, c_);
                        // cout << c_;
                        // cout << 'c';
                        // print(temp);

                        if(temp.size() > 0) {
                            if(temp_b.size() > 0) {
                                if(abs(temp_b[temp_b.size()-1] - temp[0]) != 1) {
                                    if(k != 1) {                                            
                                        k = -10;
                                        conti = true;
                                    }
                                    continue;
                                }
                            }
                            temp_c = temp_b;
                            temp_c.insert(temp_c.end(), temp.begin(), temp.end());
                            k = -10;
                        } else {
                            temp_c = temp_b;
                            k -= 10;
                        }
                    }

                    if(conti) {
                        continue;
                    }
                    // cout << "abc";
                    // print(temp_c);
                    sol = temp_c;
                    pos = true;
                }
            }
        }
    }

    if(pos) {
        cout << "YES\n";
        print(sol);
    } else {
        cout << "NO\n";
    }

    return 0;
}