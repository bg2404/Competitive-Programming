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
	bfs(0, 0)
	print("\n")
}

func bfs(u, p int) {
	var q []int
	q = append(q, u)
	vis[u] = true
	for len(q) > 0 {
		fmt.Printf("%d ", q[0])
		for _, v := range adj[q[0]] {
			if !vis[v] {
				q = append(q, v)
				vis[v] = true
			}
		}
		q = q[1:]
	}
}
