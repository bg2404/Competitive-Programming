def solution(data, n): 
    # Your code here
    ret = []
    count = {}
    for d in data:
        if d not in count:
            count[d] = 1
        else:
            count[d] = count[d] + 1
    for d in data:
        if count[d] <= n:
            ret.append(d)
    return ret

data = map(int, raw_input().split())
n = int(raw_input())

print solution(data, n)
