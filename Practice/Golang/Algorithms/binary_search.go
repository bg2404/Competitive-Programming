package main

import (
	"fmt"
	"sort"
)

func binarySearch(arr []int, k int) bool {
	l, r, m := 0, len(arr)-1, 0
	for l <= r {
		m = (l + r) / 2
		if arr[m] < k {
			l = m + 1
		} else if arr[m] > k {
			r = m - 1
		} else {
			return true
		}
	}
	return false
}

func main() {
	var n int
	var arr []int

	fmt.Scanf("%d", &n)
	arr = make([]int, n)
	for i := range arr {
		fmt.Scanf("%d", &arr[i])
	}
	sort.Ints(arr)
	fmt.Println(arr)
	m := 0
	fmt.Scanf("%d", &m)
	for i := 0; i < m; i++ {
		var k int
		fmt.Scanf("%d", &k)
		fmt.Println(binarySearch(arr, k))
	}
}
