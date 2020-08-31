#include<bits/stdc++.h>
using namespace std;

struct node{
    unordered_map<char,pair<node*,int>> children;
};

class trie{
    node *parent;
public:
    trie(){
        parent = new node();
    }
    void add(string &a){
        node *current = parent;
        for(auto &i: a){
            if(current->children.find(i) == current->children.end()){
                current->children[i].first = new node();
                current->children[i].second = 0;
            }
            current = current->children[i].first;
            current->children[i].second++;
        }
    }
    bool exists(string &a)const{
        node *current = parent;
        for(auto &i: a){
            if(current->children.find(i) == current->children.end()){
                return false;
            }
            current = current->children[i].first;
        }
        return true;
    }
};

vector<int> solve(vector<int> &A, vector<int> &B) {
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > > > pq;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    set<pair<int, int> > s;
    vector<int> ans;
    int n = A.size();
    cout << pq.size() << "(1) ";
    getchar();
    getchar();
    pq.push({A[n-1] + B[n-1], {n-1, n-1}});
    s.insert({n-1, n-1});
    cout << pq.size() << "(2) ";
    getchar();
    getchar();
    while(ans.size() < n) {
        priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > > > t;
        pair<int, pair<int, int> > top = pq.top();
        pq.pop();
        cout << pq.size() << "(3) ";
        getchar();
        getchar();
        while(pq.size() > 0) {
            cout << pq.top().first;
            t.push(pq.top());
            pq.pop();
            cout << "(" << ans.size() << ", " << pq.size() << ")";
            cout << " \n"[pq.empty() == 1];
        }
        while(!t.empty()) {
            pq.push(t.top());
            t.pop();
        }
        int l = top.second.first;
        int r = top.second.second;
        ans.push_back(top.first);
        if(l > 0 && r >= 0 && s.find({l-1, r}) == s.end()) {
            pq.push({A[l-1] + B[r], {l-1, r}});
            s.insert({l-1, r});
        }
        if(l >= 0 && r > 0 && s.find({l, r-1}) == s.end()) {
            pq.push({A[l] + B[r-1], {l, r-1}});
            s.insert({l, r-1});
        }
    }
    return ans;
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &i: a) {
        cin >> i;
    }
    for(int &i: b) {
        cin >> i;
    }
    vector<int> c = solve(a, b);
    for(int i = 0; i < n; ++i) {
        cout << c[i] << " \n"[i+1 == n];
    }
    return 0;
}