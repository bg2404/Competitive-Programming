package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }
func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }

func main() {
	var n, a, b, k int
	scanf("%d %d %d %d\n", &n, &a, &b, &k)
	h := make([]int, n)
	for i := range h {
		scanf("%d", &h[i])
	}
	move := make([]int, n)
	for i, v := range h {
		v = v % (a + b)
		if v == 0 {
			v = a + b
		}
		num := v / a
		if v % a > 0 {
			num++
		}
		move[i] = num - 1
	}
	cnt := 0
	ans := 0
	sort.Ints(move)
	for _, v := range move {
		// printf("%d ", v)
		cnt += v
		if cnt > k {
			break
		}
		ans++
	}
	printf("%d\n", ans)
	writer.Flush()
}