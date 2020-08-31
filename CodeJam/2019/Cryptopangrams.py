T = int(input())
print(T)

for t in range(0, T):
    print("Case #{}: ".format(t+1), end='')
    n, l = [int(x) for x in input().split()]
    x = [int(x) for x in input().split()]
    print(n, l)