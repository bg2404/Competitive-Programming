package main

import "fmt"

var isPrime []bool

func sieve(n int) {
	isPrime = make([]bool, n + 1)
	for i := range isPrime {
		isPrime[i] = true
	}
	isPrime[0] = false
	isPrime[1] = false
	for i := 2; i*i <= n; i++ {
		if isPrime[i] {
			for j := i * i; j <= n; j += i {
				isPrime[j] = false
			}
		}
	}
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	sieve(n)
	fmt.Println(isPrime)
}