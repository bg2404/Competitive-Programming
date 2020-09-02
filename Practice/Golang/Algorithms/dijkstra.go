package main

import "fmt"
import pq "container/heap"

type edge struct {
	to int
	w  int
}

type node struct {
	dist int
	idx int
}

type intHeap []node

func (h *intHeap) Len() int { return len(*h) }
func (h *intHeap) Swap(i, j int) { (*h)[i], (*h)[j] = (*h)[j], (*h)[i] }
func (h* intHeap) Less(i, j int) bool { return (*h)[i].dist < (*h)[j].dist }

func (h *intHeap) Push(x interface{}) {
	*h = append(*h, x.(node))
}

func (h *intHeap) Pop() interface{} {
	n := h.Len()
	x := (*h)[n-1]
	*h = (*h)[:n-1]
	return x
}

func main() {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)
	adj := make([][]edge, n)
	for i := 0; i < m; i++ {
		var u, v, w int
		fmt.Scanf("%d %d %d", &u, &v, &w)
		adj[u] = append(adj[u], edge{to:v, w:w})
		adj[v] = append(adj[v], edge{to:u, w:w})
	}
	fmt.Println(dijkstra(adj, 2))
}

func dijkstra(adj [][]edge, s int) []int {
	n := len(adj)
	vis := make([]bool, n)
	dist := make([]int, n)
	h := &intHeap{}
	pq.Init(h)
	pq.Push(h, node{dist:0, idx:s})
	for h.Len() > 0 {
		cur := pq.Pop(h).(node)
		
		if vis[cur.idx] {
			continue
		} else {
			vis[cur.idx] = true
			dist[cur.idx] = cur.dist
			for _, e := range adj[cur.idx] {
				if !vis[e.to] {
					pq.Push(h, node{dist:cur.dist + e.w, idx:e.to})
				}
			}
		}
	}
	return dist
}