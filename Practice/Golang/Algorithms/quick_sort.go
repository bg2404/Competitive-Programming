package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	slice := generateSlice(10)
	fmt.Println(slice)
	quickSort(slice)
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

func quickSort(a []int) {
	if len(a) < 2 {
		return
	}

	left, right := 0, len(a) - 1
	pivot := rand.Intn(right + 1)

	a[right], a[pivot] = a[pivot], a[right]
	for i := range a {
		if a[i] < a[right] {
			a[left], a[i] = a[i], a[left]
			left++
		}
	}
	a[left], a[right] = a[right], a[left]
	quickSort(a[:left])
	quickSort(a[left+1:])
}