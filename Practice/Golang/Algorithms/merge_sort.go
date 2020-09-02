package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	slice := generateSlice(10)
	fmt.Println(slice)
	slice = mergeSort(slice)
	fmt.Println(slice)
}

func generateSlice(n int) []int {
	slice := make([]int, n)
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < n; i++ {
		slice[i] = rand.Intn(1000) - rand.Intn(1000)
	}
	return slice
}

func mergeSort(a []int) []int {
	n := len(a)
	if n < 2 {
		return a
	}
	m := n / 2
	l, r := make([]int, m), make([]int, n-m)
	for i := 0; i < m; i++ {
		l[i] = a[i]
	}
	for i := m; i < n; i++ {
		r[i-m] = a[i]
	}
	l = mergeSort(l)
	r = mergeSort(r)
	return merge(l, r)
}

func merge(a, b []int) []int {
	c := make([]int, len(a)+len(b))
	i, j, k := 0, 0, 0
	for j < len(a) && k < len(b) {
		if a[j] < b[k] {
			c[i] = a[j]
			j++
		} else {
			c[i] = b[k]
			k++
		}
		i++
	}

	for j < len(a) {
		c[i] = a[j]
		j++
		i++
	}

	for k < len(b) {
		c[i] = b[k]
		k++
		i++
	}
	return c
}
