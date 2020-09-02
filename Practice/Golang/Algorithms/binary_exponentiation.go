package main

import "fmt"

const mod = 1000000007

func binPowMod(a, n int) int {
	a %= mod
	ret := 1
	for n > 0 {
		if n&1 == 1 {
			ret = (ret * a) % mod
		}
		a = (a * a) % mod
		n >>= 1
	}
	return ret
}

func main() {
	var a, n int
	fmt.Scanf("%d %d", &a, &n)
	fmt.Printf("%d\n", binPowMod(a, n))
}
