package main

import (
	pq "container/heap"
	"fmt"
)

type IntHeap []int

func (h *IntHeap) Len() int {
	return len(*h)
}

func (h *IntHeap) Less(i, j int) bool {
	return (*h)[i] < (*h)[j]
}

func (h *IntHeap) Swap(i, j int) {
	(*h)[i], (*h)[j] = (*h)[j], (*h)[i]
}

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	n := len(*h)
	x := (*h)[n-1]
	*h = (*h)[:n-1]
	return x
}

func main() {
	h := &IntHeap{9, 8, 7, 6, 4, 3, 2}
	pq.Init(h)
	fmt.Println(*h)
	fmt.Println(pq.Pop(h))
	fmt.Println(pq.Pop(h))
	fmt.Println(pq.Pop(h))
	pq.Push(h, 1)
	fmt.Println(pq.Pop(h))
	for h.Len() > 0 {
		fmt.Printf("%d ", pq.Pop(h))
	}
	fmt.Println()
}
