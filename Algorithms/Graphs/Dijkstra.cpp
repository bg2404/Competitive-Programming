#include<bits/stdc++.h>
#define LONG_INF (long long)(1e18+7)
using namespace std;

vector<vector<pair<int, long long> > > adj;
vector<long long> dist;
vector<int> parent;

template<typename T>
struct NODE {
    T v;

    NODE(T v) {
        this->v = v;
    }

    bool operator<(const NODE &other) const {
        return dist[v] < dist[other.v];
    }

    bool operator>(const NODE &other) const {
        return dist[v] > dist[other.v];
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
    void decreaseDist(int i, long long d);
    void deleteKey(int i);
    void print() {
        for(auto i: heap) {
            cout << i.v << ' ';
        }
        cout << '\n';
        for(auto i: heap) {
            cout << dist[i.v] << ' ';
        }
        cout << '\n';
        for(auto i: pos) {
            cout << "(" << i.first << ", " << i.second << ") ";
        }
        cout << '\n';
    }
    int size() {
        return heap.size();
    }
    bool empty() {
        return heap.size() == 0;
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
void MinHeap<T>::decreaseDist(int i, long long d) {
    if(dist[heap[i].v] <= d) {
        return;
    }
    dist[heap[i].v] = d;
    while(i > 0 && heap[parent(i)] > heap[i]) {
        swap(pos[heap[i].v], pos[heap[parent(i)].v]);
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

template<typename T>
void MinHeap<T>::decreaseKey(int i, T k) {
    if(heap[i].v <= k) {
        return;
    }
    heap[i].v = k;
    while(i > 0 && heap[parent(i)].v > heap[i].v) {
        swap(pos[heap[i].v], pos[heap[parent(i)].v]);
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

template<typename T>
void MinHeap<T>::deleteKey(int i) {
    decreaseKey(i, INT_MIN);
    extractMin();
}

void dijkstra(int s, int n) {
    MinHeap<int> mh;
    for(int i = 0; i < n; ++i) {
        dist[i] = LONG_INF;
        parent[i] = -1;
        mh.insert(i);
    }
    mh.decreaseDist(mh.pos[s], 0);

    while(!mh.empty()) {
        int u = mh.extractMin();
        for(auto i: adj[u]) {
            int v = i.first;
            long long w = i.second;
            long long d = dist[u] + w;
            cout << u << ' ' << v << ' ' << w << '\n';
            if(d < dist[v]) {
                parent[v] = u;
                mh.decreaseDist(mh.pos[v], d);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj = vector<vector<pair<int, long long> > > (n, vector<pair<int, long long> >());
    dist = vector<long long>(n);
    parent = vector<int>(n);
    for(int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u-1].push_back({v-1, w});
        adj[v-1].push_back({u-1, w});
    }
    cout.flush();
    dijkstra(1, n);
    for(int i = 0; i < dist.size(); ++i) {
        if(parent[i] < 0) {
            cout << setw(2);
        }
        cout << dist[i] << ' ';
    }
    cout << '\n';
    for(int p: parent) {
        cout << p << ' ';
    }
    cout << '\n';
    return 0;
}