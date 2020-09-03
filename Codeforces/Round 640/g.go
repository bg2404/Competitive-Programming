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
	if n < 4 {
		printf("-1\n")
	} else if n == 4 {
		printf("3 1 4 2\n")
	} else {
		i := 1
		for i <= n {
			printf("%d ", i)
			i += 2
		}
		printf("%d ", i - 5)
		if n & 1 == 0 {
			printf("%d ", i - 1)
		}
		i -= 3
		printf("%d ", i)
		i -= 4
		for i > 0 {
			printf("%d ", i)
			i -= 2
		}
		printf("\n")
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