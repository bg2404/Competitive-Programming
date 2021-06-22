def query(a, b, c):
    print(f"{a} {b} {c}", flush=True)
    return int(input())


def median_sort(arr, n):
    if n < 3:
        return arr
    l1 = []
    l2 = []
    l3 = []
    for i in range(2, n):
        m = query(a=arr[0], b=arr[1], c=arr[i])
        if m == arr[0]:
            l1.append(arr[i])
        elif m == arr[1]:
            l3.append(arr[i])
        else:
            l2.append(arr[i])
    l1 = median_sort(l1, len(l1))
    l2 = median_sort(l2, len(l2))
    l3 = median_sort(l3, len(l3))
    if len(l1) > 1:
        m = query(l1[0], l1[1], arr[0])
        if m == l1[0]:
            l1 = reversed(l1)
    if len(l2) > 1:
        m = query(l2[0], l2[1], arr[0])
        if m == l2[1]:
            l2 = reversed(l2)
    if len(l3) > 1:
        m = query(l3[0], l3[1], arr[0])
        if m == l3[1]:
            l3 = reversed(l3)
    return l1 + [arr[0]] + l2 + [arr[1]] + l3


T, N, Q = map(int, input().strip().split())

for t in range(1, T + 1):
    arr = median_sort(list(range(1, N + 1)), N)
    for e in arr:
        print(e, end=" ")
    print("", flush=True)
    m = int(input())
    if m < 0:
        exit()
