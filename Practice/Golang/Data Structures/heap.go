package main

import (
	"errors"
	"fmt"
)

type heap struct {
	arr  []int
	size int
}

func (h *heap) init(arr []int) {
	h.arr = arr
	h.size = len(arr)
	for i := h.size/2 - 1; i >= 0; i-- {
		h.minHeapify(i)
	}
}

func (h *heap) minHeapify(root int) {
	l, r := root*2+1, root*2+2
	minIdx := root
	if l < h.size && h.arr[l] < h.arr[root] {
		minIdx = l
	}
	if r < h.size && h.arr[r] < h.arr[minIdx] {
		minIdx = r
	}
	if minIdx != root {
		h.arr[root], h.arr[minIdx] = h.arr[minIdx], h.arr[root]
		h.minHeapify(minIdx)
	}
}

func (h heap) getMin() (int, error) {
	if h.size == 0 {
		return 0, errors.New("Empty Heap")
	}
	return h.arr[0], nil
}

func (h *heap) extractMin() (int, error) {
	ret, err := h.getMin()
	if err != nil {
		return ret, err
	}
	h.size--
	h.arr[0], h.arr[h.size] = h.arr[h.size], h.arr[0]
	h.arr = h.arr[:h.size]
	h.minHeapify(0)

	return ret, nil
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	var arr []int = make([]int, n)
	for k := range arr {
		fmt.Scanf("%d", &arr[k])
	}
	var h heap
	h.init(arr)
	fmt.Println(h.arr)
	fmt.Println(h.extractMin())
	fmt.Println(h.arr)
	fmt.Println(h.extractMin())
	fmt.Println(h.arr)
	fmt.Println(h.extractMin())
	fmt.Println(h.arr)
	fmt.Println(h.extractMin())
}
