#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int V, E, v, u;
vector<vector<int> > G, G_rev;
vector<int> component;
vector<int> finish_time;
int t;

void init() {
    G.resize(V);
    G_rev.resize(V);
    fill(G.begin(), G.end(), vector<int>());
    fill(G_rev.begin(), G_rev.end(), vector<int>());
    component.resize(V);
    finish_time.resize(V);
    t = V;
}

void setFinishTime(vector<vector<int> > G, int v, bool visited[]) {
    visited[v] = true;
    for(auto u: G[v]) {
        if(!visited[u]) {
            setFinishTime(G, u, visited);
        }
    }
    finish_time[--t] = v;
}

void SCC(int v, int l, bool visited[]) {
    component[v] = l;
    visited[v] = true;
    for(auto u: G[v]) {
        if(!visited[u]) {
            SCC(u, l, visited);
        }
    }
}

void kosaraju() {
    bool visited[V];
    for(int i = 0; i < V; ++i) visited[i] = false;

    for(int i = 0; i < V; ++i) {
        if(!visited[i]) {
            setFinishTime(G_rev, i, visited);
        }
    }
    int l = 1;
    for(int i = 0; i < V; ++i) visited[i] = false;
    for(int i = 0; i < V; ++i) {
        if(!visited[finish_time[i]]) {
            SCC(finish_time[i],l++, visited);
        }
    }
}

int main() {
    cin >> V >> E;
    init();
    for(int i = 0; i < E; ++i) {
        cin >> v >> u;
        G[v].push_back(u);
        G_rev[u].push_back(v);
    }

    kosaraju();

    for(int i = 0; i < V; ++i) {
        cout << component[i] << ' ';
    }
    return 0;
}