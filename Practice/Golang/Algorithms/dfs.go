package main

import "fmt"

var adj [][]int
var vis []bool

func main() {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)
	adj = make([][]int, n)
	vis = make([]bool, n)
	for i := 0; i < m; i++ {
		var u, v int
		fmt.Scanf("%d %d", &u, &v)
		adj[u] = append(adj[u], v)
		adj[v] = append(adj[v], u)
	}
	dfs(0, 0)
	print("\n")
}

func dfs(u, p int) {
	fmt.Printf("(%d %d) ", u, p)
	vis[u] = true
	for _, v := range adj[u] {
		if !vis[v] {
			dfs(v, u)
		}
	}
}
