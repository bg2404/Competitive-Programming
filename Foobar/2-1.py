def solution(src, dest):
    moves = [(1, 2), (1, -2), (2, 1), (2, -1),
             (-1, 2), (-1, -2), (-2, 1), (-2, -1)]

    xs = src // 8
    ys = src % 8

    xd = dest // 8
    yd = dest % 8

    visited = [[-1]*8 for _ in range(8)]
    visited[xs][ys] = 0
    q = [(xs, ys)]

    while(len(q) > 0):
        x, y = q[0]
        q = q[1:]
        for move in moves:
            x_, y_ = x + move[0], y + move[1]
            if x_ >= 0 and y_ >= 0 and x_ < 8 and y_ < 8 and visited[x_][y_] < 0:
                visited[x_][y_] = visited[x][y] + 1
                q.append((x_, y_))
                if x_ == xd and y_ == yd:
                    q = []
                    break
    return visited[xd][yd]


s, d = tuple(map(int, raw_input().strip().split()))

print(solution(s, d))
