// https://codeforces.com/contest/339/problem/C

#include<bits/stdc++.h>

using namespace std;

struct node {
    int w;
    int last;
    int turn;
    vector<struct node*> children;
    struct node* parent;
};

void initializeNode(struct node** root, int w, int l, int t) {
    (*root) = new node;
    (*root)->w = w;
    (*root)->last = l;
    (*root)->turn = t;
}

vector<int> weighs;
stack<struct node*> q;
stack<struct node*> st;
struct node* root;
bool found;
int m;
void dfs(struct node* root) {
    if(root->turn == m) {
        found = true;
        st.push(root);
        return;
    }
    for(int w: weighs) {
        if(root->turn & 1) {
            if(root->w - w < 0 && w != root->last) {
                struct node* newNode;
                initializeNode(&newNode, root->w - w, w, root->turn+1);
                newNode->parent = root;
                dfs(newNode);
            }
        } else {
            if(root->w + w > 0 && w != root->last) {
                struct node* newNode;
                initializeNode(&newNode, w + root->w, w, root->turn+1);
                newNode->parent = root;
                dfs(newNode);
            }
        }
        if(found) {
            break;
        }
    }

    if(!found) {
        delete root;
    } else {
        st.push(root);
    }
}

int main() {
    string s;
    cin >> s;
    for(int i = 0; i < 10; ++i) {
        if(s[i] == '1') {
            weighs.push_back(i+1);
        }
    }
    cin >> m;
    initializeNode(&root, 0,0,0);
    dfs(root);

    if(!found) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        while(!st.empty()) {
            if(st.top()->turn ==0) {
                st.pop();
                continue;
            }
            cout << st.top()->last << ' ';
            delete st.top();
            st.pop();
        }
    }

    return 0;
}