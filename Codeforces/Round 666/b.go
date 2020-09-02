package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

const inf int64 = 100000000000000000

func add(a, b int64) int64 {
	if a+b > inf {
		return inf
	}
	return a + b
}

func mul(a, b int64) int64 {
	if inf/a > b {
		return a * b
	}
	return inf
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	defer writer.Flush()
	var n int
	scanf("%d\n", &n)
	// fmt.Println(n)
	a := make([]int, n)
	for i := range a {
		scanf("%d ", &a[i])
	}
	sort.Ints(a)

	if n < 3 {
		printf("%d\n", a[0] - 1)
	} else {
		var minCost int64 = 0
		for _, v := range a {
			minCost += int64(v)
		}
		minCost -= int64(n)
		var x int64 = 0
		for x = 1; ; x++ {
			var cost, powCur int64 = 0, 1
			for i := range a {
				cost = add(cost, abs(int64(a[i])-powCur))
				powCur = mul(powCur, x)
			}
			if powCur >= inf || powCur/x > minCost+int64(a[n-1]) {
				break
			}
			minCost = min(minCost, cost)
		}
		printf("%d\n", minCost)
	}
}
