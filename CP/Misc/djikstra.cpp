#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> loc;

class Heap {
    int MAX;
    int n;
    vector<int> heap;
    void heapify(int v);
public:
    Heap(int MAX);
    void insert(int v);
    int extractMin();
    void del();
};

Heap::Heap(int MAX) {
    this->MAX = MAX;
    heap.resize(MAX);
    n = 0;
}

void Heap::heapify(int v) {
    int l = (v*2 + 1 < n) ? v*2 + 1 : -1;
    int r = (v*2 + 2 < n) ? v*2 + 2 : -1;
    if(l >= 0 && heap[l] < heap[v]) {
        swap(heap[l], heap[v]);
        heapify(l);
    } else if(r >= 0 && heap[r] < heap[v]) {
        swap(heap[r], heap[v]);
        heapify(r);
    }
}

void Heap::insert(int v) {
    heap[n] = v;
    loc[v] = n++;
    int pos = n-1;
    while(pos > 0) {
        int p = (pos - 1) / 2;
        if(heap[p] > heap[pos]) {
            swap(heap[p], heap[pos]);
            swap(loc[heap[p]], loc[heap[pos]]);
            pos = p;
        } else {
            break;
        }
    }
}

int Heap::extractMin() {
    swap(heap[0], heap[--n]);
    heapify(0);
    return heap[n];
}



class Graph {
    int V;
    vector<vector<int> > adj;
public:
    Graph(int V);
    void insertEdge(int v, int u);
    void djikstra(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
    fill(adj.begin(), adj.end(), vector<int>());
    loc.resize(V);
}

void Graph::insertEdge(int v, int u) {
    adj[v].push_back(u);
}

void Graph::djikstra(int s) {
    bool done[V];
    int minDist[V];
    for(int i = 0; i < V; ++i) done[i] = false, minDist[i] = 1e9;
    done[s] = true;
    minDist[s] = 0;
    
}

int main() {

    return 0;
}