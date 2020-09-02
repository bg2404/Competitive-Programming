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
	t, n := 0, 0
	scanf("%d\n", &t)
	for t > 0 {
		t--
		scanf("%d\n", &n)
		
		p := 1
		var a []int
		for n > 0 {
			if n % 10 > 0 {
				a = append(a, p * (n % 10))
			}
			n /= 10
			p *= 10
		}
		printf("%d\n", len(a))
		for _, v := range a {
			printf("%d ", v)
		}
		printf("\n")
	}
	writer.Flush()
}
