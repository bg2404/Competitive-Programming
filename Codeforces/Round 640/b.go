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
	var n, k int
	scanf("%d %d\n", &n, &k)

	if n < k {
		printf("NO\n")
	} else {
		if n & 1 == 0 {
			if n >= 2*k {
				printf("YES\n")
				for i := 1; i < k; i++ {
					printf("2 ")
					n -= 2
				}
				printf("%d\n", n)
			} else {
				if k & 1 == 1 {
					printf("NO\n")
				} else {
					printf("YES\n")
					for i := 1; i < k; i++ {
						printf("1 ")
						n--
					}
					printf("%d\n", n)
				}
			}
		} else {
			if k & 1 == 1 {
				printf("YES\n")
				for i := 1; i < k; i++ {
					printf("1 ")
					n--
				}
				printf("%d\n", n)
			} else {
				printf("NO\n")
			}
		}
	}
}

func main() {
	var t int
	scanf("%d\n", &t)
	for t > 0 {
		t--
		solve()
	}
	writer.Flush()
}