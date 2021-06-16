import numpy as np


def take_input(nrows, ncols, input_prompt=""):
    matrix = []
    for r in range(nrows):
        matrix.append(list(map(float, input(
            input_prompt + " (row #" + str(r) + "): ").strip().split()))[:ncols])
    return np.matrix(matrix)


def add_slack(nrows, A, c):
    extra = np.zeros((nrows, 1))
    for r in range(nrows):
        c = np.append(c, 0)
        extra[r] = 1.
        np.append(A, extra, axis=1)
        extra[r] = 0.
    return A, c



M = int(input("Number of constraints: "))
N = int(input("Number of variables: "))

A = take_input(M, N, "A")
b = take_input(M, 1, "b")
c = take_input(N, 1, "c")



A, c = add_slack(M, A, c)

print(A)
print(b)
print(c)
