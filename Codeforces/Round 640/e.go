package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }
func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }

func solve() {
	n := 0
	scanf("%d\n", &n)
	a := make([]int, n)
	p := make([]int, n + 1)
	m := make([]bool, n+1)
	p[0] = 0
	for i := 1; i < n; i++ {
		scanf("%d ", &a[i-1])
		p[i] = p[i-1] + a[i-1]
	}
	scanf("%d\n", &a[n-1])
	p[n] = p[n-1] + a[n-1]
	for i := 0; i < n; i++ {
		for j := i + 2; j <= n; j++ {
			if(p[j] - p[i] <= n) {
				m[p[j] - p[i]] = true
			}
		}
	}
	cnt := 0
	for _, v := range a {
		if m[v] {
			cnt++
		}
	}
	printf("%d\n", cnt)

}

func main() {
	t := 0
	scanf("%d\n", &t)
	for t > 0 {
		solve()
		t--
	}
	writer.Flush()
}