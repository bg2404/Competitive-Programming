def change(a, rev=False):
    if rev:
        if a == '0':
            return '1'
        return '0'
    return a


t = int(input())
while t > 0:
    t = t - 1
    n = int(input())
    a = input()
    b = input()
    pa = [0]
    for c in a:
        pa.append(pa[-1] + int(c))
    # print(pa)
    pos = True
    rev = False
    for i in reversed(range(n)):
        if change(a[i], rev) != b[i]:
            # print(str(i) + " " + a[i] + " " + str(rev) + " " + b[i])
            if i % 2 == 0 or pa[i+1] != (i + 1) // 2:
                pos = False
                break
            rev = not rev
    if pos:
        print("YES")
    else:
        print("NO")
