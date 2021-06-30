T = int(input())
MOD = int(1000000007)
for t in range(T):
	N, K = map(int, input().split())
	X = (K-1) // (N-1) + 1
	S = X*(K-1) - X*(X-1)*(N-1)/2
	print(int(S%MOD))
