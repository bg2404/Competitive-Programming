#include<bits/stdc++.h>

using namespace std;

template<typename T>
struct NODE {
    T v;

    NODE(T v) {
        this->v = v;
    };

    bool operator==(const NODE &other) const {
        return v == other.v;
    }

    bool operator!=(const NODE &other) const {
        return v != other.v;
    }

    bool operator<(const NODE &other) const {
        return v < other.v;
    }

    bool operator<=(const NODE &other) const {
        return v <= other.v;
    }

    bool operator>(const NODE &other) const {
        return v > other.v;
    }

    bool operator>=(const NODE &other) const {
        return v >= other.v;
    }
};

template<typename T>
class MinHeap {
private:
    vector<struct NODE<T> > heap;
    int parent(int i) {
        return (i-1)/2;
    }
    int left(int i) {
        return 2*i + 1;
    }
    int right(int i) {
        return 2*i + 2;
    }
    void minHeapify(int i);
public:
    map<T, int> pos;
    MinHeap() {
        heap.clear();
    }
    MinHeap(vector<T> &a);
    void insert(T k);

    T getMin() {
        return heap[0].v;
    }
    T extractMin();
    void decreaseKey(int i, T k);
    void deleteKey(int i);
    int size() {
        return heap.size();
    }
    bool empty() {
        return heap.size() == 0;
    }
    void print() {
        for(int i = 0; i < heap.size(); ++i) {
            cout << heap[i].v << ' ';
        }
        cout << '\n';
        for(int i = 0; i < heap.size(); ++i) {
            cout << pos[heap[i].v] << ' ';
        }
        cout << '\n';
    }
};

template<typename T>
void MinHeap<T>::minHeapify(int i) {
    int l = left(i), r = right(i);
    int smallest = i;
    if(l < heap.size() && heap[l] < heap[smallest]) {
        smallest = l;
    }
    if(r < heap.size() && heap[r] < heap[smallest]) {
        smallest = r;
    }
    if(smallest != i) {
        swap(pos[heap[i].v], pos[heap[smallest].v]);
        swap(heap[i], heap[smallest]);
        minHeapify(smallest);
    }
}

template<typename T>
MinHeap<T>::MinHeap(vector<T> &a) {
    for(T i: a) {
        heap.clear();
        NODE<T> node(i);
        pos[i] = heap.size();
        heap.push_back(node);
    }
    for(int i = parent(heap.size()-1); i >= 0; --i) {
        minHeapify(i);
    }
}

template<typename T>
void MinHeap<T>::insert(T k) {
    int i = heap.size();

    NODE<T> node(k);
    heap.push_back(node);
    pos[k] = i;
    while(i && heap[parent(i)] > heap[i]) {
        swap(pos[heap[i].v], pos[heap[parent(i)].v]);
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

template<typename T>
T MinHeap<T>::extractMin() {
    T root = getMin();
    pos.erase(heap[0].v);
    heap[0] = heap[heap.size()-1];
    pos[heap[0].v] = 0;
    heap.pop_back();
    minHeapify(0);
    return root;
}

template<typename T>
void MinHeap<T>::decreaseKey(int i, T k) {
    NODE<T> node(k);
    if(heap[i] <= node) {
        return;
    }
    heap[i] = node;
    while(i > 0 && heap[parent(i)] > heap[i]) {
        swap(pos[heap[i].v], pos[heap[parent(i)].v]);
        swap(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}

template<typename T>
void MinHeap<T>::deleteKey(int i) {
    decreaseKey(i, INT_MIN);
    extractMin();
}

int main() {
    srand(time(0));
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    MinHeap<int> mh;
    for(int i = 0; i < a.size(); ++i) {
        mh.insert(a[i]);
    }
    cout << "getMin(): ";
    cout << mh.getMin() << '\n';
    mh.print();
    cout << "extractMin(): " << mh.extractMin() << '\n';
    mh.print();
    mh.decreaseKey(4, 2);
    cout << "decreaseKey(4, 2): \n";
    mh.print();
    cout << "deleteKey(4): \n";
    mh.deleteKey(4);
    mh.print();
    return 0;
}