package main

import (
	"fmt"
	"math"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

var segmentTree []int
var sizeSegmentTree int

func initSegmentTree(arr []int, n int) {
	sizeSegmentTree = 1
	for sizeSegmentTree < n {
		sizeSegmentTree = sizeSegmentTree * 2
	}
	segmentTree = make([]int, sizeSegmentTree*2-1)
	for i := range segmentTree {
		segmentTree[i] = math.MaxInt32
	}
	buildSegmentTree(arr, 0, 0, sizeSegmentTree-1)
}

func buildSegmentTree(arr []int, root, l, r int) {
	if l == r {
		if r < len(arr) {
			segmentTree[root] = arr[l]
		}
	} else if l < r {
		m := (l + r) / 2
		buildSegmentTree(arr, root*2+1, l, m)
		buildSegmentTree(arr, root*2+2, m+1, r)
		segmentTree[root] = min(segmentTree[root*2+1], segmentTree[root*2+2])
	}
}

func updateSegmentTree(root, l, r, idx, v int) {
	if l <= r && l <= idx && r >= idx {
		if l == r {
			if l == idx {
				segmentTree[root] = v
			}
		} else {
			m := (l + r) / 2
			if idx > m {
				updateSegmentTree(root*2+2, m+1, r, idx, v)
			} else {
				updateSegmentTree(root*2+1, l, m, idx, v)
			}
			segmentTree[root] = min(segmentTree[root*2+1], segmentTree[root*2+2])
		}
	}
}

func querySegmentTree(root, l, r, x, y int) int {
	if r < l || y < x || r < x || y < l {
		return math.MaxInt32
	}
	if x <= l && r <= y {
		return segmentTree[root]
	}
	m := (l + r) / 2
	return min(querySegmentTree(root*2+1, l, m, x, y), querySegmentTree(root*2+2, m+1, r, x, y))
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	var arr []int = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &arr[i])
	}
	initSegmentTree(arr, n)
	fmt.Println(segmentTree)
	var m int
	fmt.Scanf("%d", &m)
	for i := 0; i < m; i++ {
		var q int
		fmt.Scanf("%d", &q)
		if q == 1 {
			var idx, v int
			fmt.Scanf("%d %d", &idx, &v)
			updateSegmentTree(0, 0, sizeSegmentTree-1, idx, v)
			fmt.Println(segmentTree)
		} else {
			var l, r int
			fmt.Scanf("%d %d", &l, &r)
			fmt.Println(querySegmentTree(0, 0, sizeSegmentTree - 1, l, r))
		}

	}

}
