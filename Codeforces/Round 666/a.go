package main

import (
	"fmt"
)

func solve() {
	var n int
	fmt.Scanf("%d\n", &n)
	s := make([]string, n)
	cnt := make([]int, 26)

	for i := range s {
		fmt.Scanf("%s\n", &s[i])
		for _, c := range s[i] {
			cnt[c - 'a']++
		}
	}
	for _, v := range cnt {
		if v % n != 0 {
			fmt.Println("NO")
			return
		}
	}
	fmt.Println("YES")
}

func main() {
	var t int
	fmt.Scanf("%d\n", &t)
	for t > 0 {
		solve()
		t--
	}
}