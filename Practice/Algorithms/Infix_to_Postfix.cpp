#include<bits/stdc++.h>

using namespace std;

int precedence(string s) {
    char op = s[0];
    if(op == '+' || op == '-') {
        return 2;
    } else if(op == '*' || op == '/') {
        return 3;
    } else if(op == '(') {
        return 0;
    }
    return 1;
}

bool isOperator(string s) {
    char c = s[0];
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
        return true;
    }
    return false;
}

string getNext(string &s) {
    if(s.length() == 0) {
        return "";
    }
    string ret = s.substr(0,1);
    if(!isOperator(ret)) {
        for(int i = 1; i < s.length(); ++i) {
            if(isOperator(s.substr(i, 1))) {
                break;
            } else {
                ret.push_back(s[i]);
            }
        }
    }
    s = s.substr(ret.length(), s.length() - ret.length());
    return ret;
}

string toPostfix(string s) {
    string postfix = "";
    stack<string> st;
    while(!s.empty()) {
        string n = getNext(s);
        if(n.size() == 0) {
            return postfix;
        }
        if(isOperator(n)) {
            if(n != "(") {
                while(!st.empty() && precedence(st.top()) >= precedence(n)) {
                    postfix += st.top() + " ";
                    st.pop();
                }
            }
            if(n == ")") {
                if(!st.empty() && st.top() == "(") {
                    st.pop();
                }
            } else {
                st.push(n);
            }
        } else {
            postfix = postfix + n + " ";
        }
    }
    while(!st.empty()) {
        postfix = postfix + st.top() + " ";
        st.pop();
    }
    return postfix;
}

int main() {
    freopen("in.txt", "r", stdin);
    string s;
    cin >> s;
    cout << s << " -> ";
    cout << toPostfix(s) << '\n';
    return 0;
}