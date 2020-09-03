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

type point struct {
	x int
	y int
}

func solve() {
	var n int
	scanf("%d\n", &n)
	var s string
	scanf("%s\n", &s)
	idx, len, x, y := -1, n+1, 0, 0
	m := make(map[point]int)
	m[point{x: 0, y: 0}] = 0

	for i := 0; i < n; i++ {
		switch s[i] {
		case 'L':
			x--
		case 'R':
			x++
		case 'U':
			y++
		case 'D':
			y--
		default:
			x++
		}
		p := point{x: x, y: y}
		if _, ok := m[p]; ok {
			l := i + 1 - m[p]
			if l < len {
				len = l
				idx = i + 1
			}
		}
		m[p] = i + 1
	}
	if len <= n {
		printf("%d %d\n", idx-len+1, idx)
	} else {
		printf("-1\n")
	}
}

func main() {
	t := 1
	scanf("%d\n", &t)
	for t > 0 {
		solve()
		t--
	}
	writer.Flush()
}
