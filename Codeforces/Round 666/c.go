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

func main() {
	var n int
	scanf("%d\n", &n)
	var a, b []int64 = make([]int64, n), make([]int64, n)
	for i := range a {
		scanf("%d ", &a[i])
	}
	b[0] = 0
	if n == 1 {
		printf("1 1\n0\n1 1\n0\n1 1\n%d\n", -a[0])
	} else {
		printf("1 1\n%d\n1 %d\n", -a[0], n)
		a[0] = 0
		for i := 0; i < n; i++ {
			printf("%d ", -int64(n)*a[i])
		}
		printf("\n2 %d\n", n)
		for i := 1; i < n; i++ {
			printf("%d ", int64(n-1)*a[i])
		}
		printf("\n")
	}
	writer.Flush()
}