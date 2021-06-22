t = int(input())

while t > 0:
    t = t - 1
    s = input()
    found = False
    n = len(s)
    i, j = 0, n - 1
    while i <= j:
        if s[i] != 'a':
            found = True
            print("YES")
            print(s[:j+1] + 'a' + s[j+1:])
            break;
        elif s[j] != 'a':
            found = True
            print("YES")
            print(s[:i] + 'a' + s[i:])
            break;
        i = i + 1
        j = j - 1
    if not found:
        print("NO")