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
	var n0, n1, n2 int
	scanf("%d %d %d\n", &n0, &n1, &n2)

	ans := ""

	if n1 == 0 {
		if n2 > 0 {
			ans = "1"
			for n2 > 0 {
				ans = ans + "1"
				n2--
			}
		}
		if n0 > 0 {
			ans = "0"
			for n0 > 0 {
				ans = ans + "0"
				n0--
			}
		}
	} else {
		if n1 & 1 == 0 {
			ans = "10"
			for n0 > 0 {
				ans = ans + "0"
				n0--
			}
			ans = ans + "1"
			n1 -= 2
			for n1 > 0 {
				ans = ans + "01"
				n1 -= 2
			}
			for n2 > 0 {
				ans = ans + "1"
				n2--
			}
		} else {
			ans = "1"
			for n2 > 0 {
				ans = ans + "1"
				n2--
			}
			ans = ans + "0"
			n1--
			for n1 > 0 {
				ans = ans + "10"
				n1 -= 2
			}
			for n0 > 0 {
				ans = ans + "0"
				n0--
			}
		}
	}
	printf("%s\n", ans)
	writer.Flush()
}

func main() {
	t := 0
	scanf("%d\n", &t)
	for t > 0 {
		solve()
		t--
	}
}