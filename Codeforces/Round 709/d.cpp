#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

struct node {
    int l;
    int r;
    node* back;
    node* next;
    node(int x) : l(x), r(x) {
        back = NULL;
        next = NULL;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, pos = 1;
        cin >> n;
        vector<int> a(n);
        node *front, *back;
        cin >> a[0];
        front = new node(0);
        back = front;
        for (int i = 1; i < n; ++i) {
            cin >> a[i];
            back->next = new node(i);
            back = back->next;
        }
        vector<int> v;
        node* cur = front;
        while (front != back) {
            if (cur->next == NULL) {
                pos = 1;
                if (gcd(a[cur->r], a[front->l]) == 1) {
                    v.push_back(pos);
                    if (front->l == front->r) {
                        node* temp = front;
                        front = front->next;
                        delete temp;
                    } else {
                        ++front->l;
                    }
                }
                cur = front;
            } else {
                if (gcd(a[cur->r], a[cur->next->l]) == 1) {
                    pos += cur->r + cur->l - 1;
                    v.push_back(pos);
                    if (cur->next->l == cur->next->r) {
                        node* temp = cur->next;c
                        cur->next = cur->next->next;
                        delete temp;
                    } else {
                        ++cur->next->l;
                    }
                    if (cur->next != NULL) {
                        cur = cur->next;
                    } else {
                        cur = front;
                        pos = 1;
                    }
                } else {
                    ;
                }
            }
            cout << v.size() << ' ';
            for (int x : v) {
                cout << x << ' ';
            }
            cout << endl;
        }
        return 0;
    }