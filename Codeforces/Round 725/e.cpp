#include <bits/stdc++.h>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    os << "[ ";
    for (T e : v) {
        os << '\'' << e << "\' ";
    }
    os << ']';
    return os;
}

vector<string> split(string &s, string delim) {
    vector<string> v;
    int last = 0;
    int pos = 0;
    while ((pos = s.find(delim, last)) != string::npos) {
        v.push_back(s.substr(last, pos - last));
        last = pos + 1;
    }
    v.push_back(s.substr(last));
    return v;
}

struct value {
    string begin;
    string end;
    long long length;
    long long cnt;
    value() {
        begin = end = "";
        length = cnt = 0;
    }
    value(string &s) {
        length = s.length();
        if (length < 4) {
            begin = end = s;
        } else {
            begin = s.substr(0, 3);
            end = s.substr(length - 3, 3);
        }
        cnt = 0;
        for (int i = 0; i + 3 < length; ++i) {
            if (s.substr(i, 4) == "haha") {
                ++cnt;
                ++i;
            }
        }
    }

    struct value operator+(const struct value &o) {
        struct value r;
        r.begin = begin + o.begin;
        r.end = end + o.end;
        r.length = length + o.length;
        r.cnt = cnt + o.cnt;
        if (r.begin.length() > 3) {
            r.begin = r.begin.substr(0, 3);
        }
        if (r.end.length() > 3) {
            r.end = r.end.substr(r.end.length() - 3, 3);
        }
        string temp = end + o.begin;
        for (int i = 0; i + 3 < temp.length(); ++i) {
            if (temp.substr(i, 4) == "haha") {
                ++r.cnt;
                ++i;
            }
        }
        return r;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_map<string, struct value> mp;
        getchar();
        string s;
        struct value ans;
        while (n--) {
            getline(cin, s);
            auto statement = split(s, " ");
            if (statement.size() == 3) {
                ans = mp[statement[0]] = value(statement[2]);
            } else {
                ans = mp[statement[0]] = mp[statement[2]] + mp[statement[4]];
            }
        }
        cout << ans.cnt << endl;
    }
    return 0;
}