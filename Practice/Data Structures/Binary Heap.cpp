#include<bits/stdc++.h>

using namespace std;

class HEAP {
    vector<int> heap;
    void heapify(int i) {
        int l = i << 1 | 1, r = (i << 1) + 2;
        int maxIdx = i;
        if(l < heap.size() && heap[maxIdx] < heap[l]) {
            maxIdx = l;
        }
        if(r < heap.size() && heap[maxIdx] < heap[r]) {
            maxIdx = r;
        }
        if(i != maxIdx) {
            swap(heap[i], heap[maxIdx]);
            heapify(maxIdx);
        }
    }
public:
    HEAP() {

    }
    HEAP(vector<int> v) {
        heap = v;
        int n = v.size();
        for(int i = n - 1; i >= 0; --i) {
            heapify(i);
        }
    }
    void insert(int v) {
        heap.push_back(v);
        int i = heap.size() - 1, p;
        while(i > 0) {
            p = (i - 1) >> 1;
            if(heap[p] < heap[i]) {
                swap(heap[p], heap[i]);
                i = p;
                p = (i - 1) >> 1;
            } else {
                break;
            }
        }
    }
    int getMax() {
        if(!heap.empty()) {
            return heap[0];
        }
        return INT_MIN;
    }
    int extractMax() {
        int ret = getMax();
        if(ret > INT_MIN) {
            swap(heap[0], heap[heap.size() - 1]);
            heap.pop_back();
            heapify(0);
        }
        return ret;
    }
    void print() {
        for(int i = 0; i < heap.size(); ++i) {
            cout << heap[i] << ' ';
        }
        cout << '\n';
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    HEAP heap(a);
    heap.print();
    for(int i = 0; i < 5; ++i) {
        int v;
        cin >> v;
        heap.insert(v);
    }
    heap.print();
    for(int i = 0; i < 6; ++i) {
        cout << heap.extractMax() << '\n';
    }
    heap.print();
    return 0;
}