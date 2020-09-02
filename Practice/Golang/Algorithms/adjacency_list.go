package main

import "fmt"

var adj [][]int

func main() {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)
	adj = make([][]int, n)
	for i := 0; i < m; i++ {
		var u, v int
		fmt.Scanf("%d %d", &u, &v)
		adj[u] = append(adj[u], v)
		adj[v] = append(adj[v], u)
	}
	fmt.Println(adj)
}
