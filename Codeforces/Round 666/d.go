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
	var a []int = make([]int, n)
	var cnt int = 0
	for i := 0; i < n-1; i++ {
		scanf("%d ", &a[i])
	}
	scanf("%d\n", &a[n-1])
	var sum int = 0
	for _, v := range a {
		sum += v
	}

	for _, v := range a {
		if v > sum / 2 {
			printf("T\n")
			return
		}
		if v > (sum - 1) / 2 {
			cnt++
		}
	}

	if sum&1 == 0 {
		printf("HL\n")
		return
	}

	if cnt > 1 {
		printf("HL\n")
	} else {
		printf("T\n")
	}

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
