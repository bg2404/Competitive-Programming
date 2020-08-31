#include<bits/stdc++.h>

using namespace std;


map<int, bool> mp;

class Graph 
{ 
	int V; // No. of vertices 

	// Pointer to an array containing 
	// adjacency lists 
	list<int> *adj; 

	// A recursive function used by DFS 
	void DFSUtil(int v, bool visited[]); 
public: 
	Graph(int V); // Constructor 

	// function to add an edge to graph 
	void addEdge(int v, int w); 

	// DFS traversal of the vertices 
	// reachable from v 
	void DFS(int v); 

    void BFS(int i, int j, int n);
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
} 

void Graph::DFSUtil(int v, bool visited[]) 
{ 
	// Mark the current node as visited and 
	// print it 
	visited[v] = true; 
	cout << v << " "; 

	// Recur for all the vertices adjacent 
	// to this vertex 
	list<int>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
		if (!visited[*i]) 
			DFSUtil(*i, visited); 
} 

// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
void Graph::DFS(int v) 
{ 
	// Mark all the vertices as not visited 
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	// Call the recursive helper function 
	// to print DFS traversal 
	DFSUtil(v, visited); 
} 

void Graph::BFS(int s, int x, int n) {
    queue<int> q;
    vector<bool> used(n, false);
    vector<int> d(n), p(n);

    q.push(s);
    used[s] = true;
    d[s] = 0;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }

    return d[x];
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    bool solved = false;

    Graph G(n);

    int a, b;
    for(int i = 0; i < k; ++i) {
        cin >> a;
        mp[a] = true;
    }

    for(int i = 0; i < m; ++i) {
        cin >> a >> b;
        G.addEdge(a,b);
        G.addEdge(b,a);
        if(mp[a] && mp[b]) {
            solved = true;
        }
    }

    if(solved) {
        //  print ans;
    } else {
        
    }

    return 0;
}