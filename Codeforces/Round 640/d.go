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
	var n int
	scanf("%d\n", &n)
	a := make([]int, n)
	for i := 0; i < n-1; i++ {
		scanf("%d ", &a[i])
	}
	scanf("%d\n", &a[n-1])
	var as, bs, l, r, s, p, t int
	r = n-1

	for l <= r {
		if t & 1 == 0 {
			for l <= r && s <= p {
				s += a[l]
				l++
			}
			p = s
			as += s
			s = 0
		} else {
			for l <= r && s <= p {
				s += a[r]
				r--
			}
			p = s
			bs += s
			s = 0
		}
		t++
	}

	printf("%d %d %d\n", t, as, bs)
}

func main() {
	var t int
	scanf("%d\n", &t)
	for t > 0 {
		solve()
		t--
	}
	writer.Flush()
}