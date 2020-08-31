#include<bits/stdc++.h>

using namespace std;

struct NODE {
    int key;
    NODE* left, *right;
    NODE(int key) {
        this->key = key;
        left = right = NULL;
    }
};

class BST {
    NODE* root;
    NODE* getMinNode(NODE* root) {
        if(root == NULL || root->left == NULL) {
            return root;
        }
        return getMinNode(root->left);
    }
    NODE* deleteKey(NODE* root, int key) {
        if(root != NULL) {
            if(root->key < key) {
                root->right = deleteKey(root->right, key);
            } else if(root->key > key) {
                root->left = deleteKey(root->left, key);
            } else {
                if(root->left == NULL) {
                    NODE* temp = root->right;
                    delete root;
                    return temp;
                } else if(root->right == NULL) {
                    NODE* temp = root->left;
                    delete root;
                    return temp;
                } else {
                    NODE* minNode = getMinNode(root->right);
                    root->key = minNode->key;
                    root->right = deleteKey(root->right, minNode->key);
                }
            }
        }
        return root;
    }
public:
    BST() {
        root = NULL;
    }
    void insertKey(int key) {
        if(root == NULL) {
            root = new NODE(key);
        } else {
            NODE* cur = root;
            while(cur != NULL) {
                if(cur->key < key) {
                    if(cur->right == NULL) {
                        cur->right = new NODE(key);
                        break;
                    }
                    cur = cur->right;
                } else {
                    if(cur->left == NULL) {
                        cur->left = new NODE(key);
                        break;
                    }
                    cur = cur->left;
                }
            }
        }
    }
    NODE* searchKey(int key) {
        NODE* cur = root;
        while(cur != NULL) {
            if(cur->key == key) {
                return cur;
            } else if(cur->key < key) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return NULL;
    }
    void deleteKey(int key) {
        root = deleteKey(root, key);
    }
    void levelOrderTraversal() {
        if(root == NULL) {
            cout << '\n';
        } else {
            queue<pair<NODE*, int> > q;
            q.emplace(root, 0);
            int prev = 0;
            while(!q.empty()) {
                NODE* cur = q.front().first;
                int h = q.front().second;
                q.pop();
                if(prev != h) {
                    cout << '\n';
                    prev = h;
                }
                cout << cur->key << ' ';
                if(cur->left != NULL) {
                    q.emplace(cur->left, h+1);
                }
                if(cur->right != NULL) {
                    q.emplace(cur->right, h+1);
                }
            }
            cout << '\n';
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    BST tree;
    tree.levelOrderTraversal();
    while(n--) {
        int k;
        cin >> k;
        tree.insertKey(k);
        tree.levelOrderTraversal();
    }
    while(m--) {
        int k;
        cin >> k;
        tree.deleteKey(k);
        tree.levelOrderTraversal();
    }
}