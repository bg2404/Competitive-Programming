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
	var n int64
	scanf("%d\n", &n)
	var ans int64
	for n > 9 {
		ans += n - n % 10
		n = n / 10 + n % 10
	}
	ans += n
	printf("%d\n", ans)
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