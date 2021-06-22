def get_parent(root, height, child):
    if root == child:
        return -1
    children = 2 ** (height-1) - 1
    right = root - 1
    left = right - children
    if right == child or left == child:
        return root
    elif child < left:
        return get_parent(root=left, height=height-1, child=child)
    else:
        return get_parent(root=right, height=height - 1, child=child)


def solution(h, q):
    return [get_parent(root=2 ** h - 1, height=h, child=x) for x in q]


li = list(map(int, raw_input().strip().split()))

h = li[0]
q = li[1:]

print(solution(h, q))
