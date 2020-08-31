#include <bits/stdc++.h>

using namespace std;

struct NODE {
    int key;
    int height;
    NODE* left, *right;
    NODE(int key) {
        this->key = key;
        height = 1;
        left = right = NULL;
    }
};

class BST {
    NODE* root;
    int getHeight(NODE* root) {
        if(root) {
            return root->height;
        }
        return 0;
    }
    int getBalance(NODE* root) {
        if(root) {
            return getHeight(root->left) - getHeight(root->right);
        }
        return 0;
    }
    NODE* getMinNode(NODE* root) {
        if(root == NULL || root->left == NULL) {
            return root;
        }
        return getMinNode(root->left);
    }
    NODE* leftRotate(NODE* x) {
        NODE* y = x->right;
        NODE* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        return y;
    }
    NODE* rightRotate(NODE* y) {
        NODE* x = y->left;
        NODE* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        return x;
    }
    NODE* insertKey(NODE* root, int key) {
        if(root == NULL) {
            return new NODE(key);
        }
        if(root->key < key) {
            root->right = insertKey(root->right, key);
        } else {
            root->left = insertKey(root->left, key);
        }
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        int balance = getBalance(root);
        if(balance > 1) {
            if(key > root->left->key) {
                root->left = leftRotate(root->left);
            }
            return rightRotate(root);
        } else if(balance < -1) {
            if(key <= root->right->key) {
                root->right = rightRotate(root->right);
            }
            return leftRotate(root);
        }
        return root;
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
        if(root == NULL) {
            return NULL;
        }
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        int balance = getBalance(root);
        if(balance > 1) {
            if(getBalance(root->left) < 0) {
                root->left = leftRotate(root->left);
            }
            return rightRotate(root);
        }
        if(balance < -1) {
            if(getBalance(root->right) > 0) {
                root->right = rightRotate(root->right);
            }
            return leftRotate(root);
        }
        return root;
    }
public:
    BST() {
        root = NULL;
    }
    void insertKey(int key) {
        root = insertKey(root, key);
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
    return 0;
}