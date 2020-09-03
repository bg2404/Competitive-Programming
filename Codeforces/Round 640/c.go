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
	var n, k, ans int64
	scanf("%d %d\n", &n, &k)
	ans = k
	cnt := ans - ans / n
	for cnt != k {
		if cnt < k {
			ans +=  k - cnt
			cnt =  ans - ans / n
		} else {
			ans -= cnt - k
			cnt = ans - ans / n
		}
	}
	printf("%d\n", ans)
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