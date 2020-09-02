package main

import "fmt"

func gcd(a, b int) int {
	for b > 0 {
		a %= b
		a, b = b, a
	}
	return a
}

func main() {
	var a, b int
	fmt.Scanf("%d %d", &a, &b)
	fmt.Println(gcd(a, b))
}