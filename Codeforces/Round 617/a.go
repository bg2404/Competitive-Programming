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
	var o, e, s int
	a := make([]int, n)
	for i := 0; i < n-1; i++ {
		scanf("%d ", &a[i])
		if a[i] & 1 == 1 {
			o++
		} else {
			e++
		}
		s += a[i]
	}
	scanf("%d\n", &a[n-1])
	if a[n-1] & 1 == 1 {
		o++
	} else {
		e++
	}
	s += a[n-1]

	if s & 1 == 1 {
		printf("YES\n")
	} else {
		if o == 0 || e == 0 {
			printf("NO\n")
		} else {
			printf("YES\n")
		}
	}
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