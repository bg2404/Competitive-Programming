#include<bits/stdc++.h>

using namespace std;

class Graph {
    int N;
    vector<int> *V;
    void computeDegree(int v, int degree[]);
    void removeEdge(int u, int v);
    int DFSCount(int v, bool visited[]);
    bool isValidNextEdge(int u, int v);
    void printEulerianUtil(int u);
public:
    Graph(int N);
    void addEdge(int u, int v);
    void checkEulerian();
    void printEulerian();
};

Graph::Graph(int N) {
    this->N = N;
    V = new vector<int>[N+1];
}

void Graph::addEdge(int u, int v) {
    V[u].push_back(v);
    V[v].push_back(u);
}

void Graph::removeEdge(int u, int v) {
    vector<int>::iterator iu = find(V[u].begin(), V[u].end(), v);
    *iu = -1;
    vector<int>::iterator iv = find(V[v].begin(), V[u].end(), u);
    *iv = -1;
}

int Graph::DFSCount(int v, bool visited[]) {
    visited[v] = true;
    int count = 1;

    vector<int>::iterator itr;
    for(itr = V[v].begin(); itr != V[v].end(); ++itr) {
        if(*itr != -1 && !visited[*itr]) {
            count += DFSCount(*itr, visited);
        }
    }
    return count;
}

void Graph::computeDegree(int v, int degree[]) {
    bool visited[N+1];
    for(int i = 0; i <= N; ++i) {
        visited[i] = false;
        degree[i] = 0;
    }

    queue<int> node_q;
    node_q.push(v);
    visited[v] = true;
    while(!node_q.empty()) {
        int v = node_q.front();
        node_q.pop();
        for(unsigned int i = 0; i < V[v].size(); ++i) {
            ++degree[V[v][i]];
            if(!visited[V[v][i]]) {
                visited[V[v][i]] = true;
                node_q.push(V[v][i]);
            }
        }
    }
}

void Graph::checkEulerian() {
    int degree[N+1];
    computeDegree(1, degree);
    int num_odds = 0;
    for(int i = 1; i <= N; ++i) {
        if(degree[i] & 1) {
            num_odds++;
        }
    }

    if(num_odds == 2) {
        cout << "Eulerian Path\n";
        printEulerian();
    } else if(num_odds == 0) {
        cout << "Eulerian Circuit\n";
        printEulerian();
    } else {
        cout << "None\n";
    }
}

bool Graph::isValidNextEdge(int u, int v) {
    int count = 0;
    vector<int>::iterator i;
    for(i = V[u].begin(); i != V[u].end(); ++i) {
        if(*i != -1) {
            count++;
        }
    }
    if(count == 1) {
        return true;
    }

    bool visited[N+1];
    memset(visited, false, N+1);
    int count1 = DFSCount(u, visited);

    removeEdge(u,v);

    memset(visited, false, N+1);
    int count2 = DFSCount(u, visited);

    addEdge(u,v);

    return count2 >= count1;
}

void Graph::printEulerianUtil(int u) {
    vector<int>::iterator i;
    for(i = V[u].begin(); i != V[u].end(); ++i) {
        int v = *i;
        if(v != -1 && isValidNextEdge(u, v)) {
            cout << u << "-" << v << '\n';
            removeEdge(u,v);
            printEulerianUtil(v);
        } 
    }
}

void Graph::printEulerian() {
    int u = 1;
    for(int i = 1; i <= N; ++N) {
        if(V[i].size() & 1) {
            u = i;
            break;
        }
    }

    printEulerianUtil(u);
    cout << '\n';
}

int main() {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    int u, v;
    for(int i = 0; i < M; ++i) {
        cin >> u >> v;
        G.addEdge(u,v);
    }
    G.checkEulerian();
    return 0;
}