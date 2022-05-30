import sys
from collections import deque
r = [1, 0, 0, -1]
c = [0, 1, -1, 0]

def V(M, Visit, r, c):
    return (r >= 0) and (r < len(M)) and (c >= 0) and (c < len(M[0])) \
           and M[r][c] == 1 and not Visit[r][c]

def Shortpath(M, s, d):
    p, q = s
    m, n = d

    if not M or len(M) == 0 or M[p][q] == 0 or M[m][n] == 0:
        return -1
    (X, Y) = (len(M), len(M[0]))

    Visit = [[False for m in range(X)] for n in range(X)]
    u = deque()
    Visit[p][q] = True
    u.append((p, q, 0))

    min_d = sys.maxsize

    while u:
        (p, q, d) = u.pop()
        if p == m and q == n:
            min_d = d
            break
        for v in range(4):
            if V(M, Visit, p + r[v], q + c[v]):
                Visit[p + r[v]][q + c[v]] = True
                u.append((p + r[v], q + c[v], d + 1))

    if min_d != sys.maxsize:
        return min_d
    else:
        return -1


if __name__ == '__main__':

    M = [
        [1, 1, 1, 1, 1, 0, 0, 1, 1, 1],
        [1, 0, 1, 0, 1, 1, 0, 1, 0, 1],
        [0, 1, 1, 0, 1, 0, 1, 0, 0, 1],
        [1, 0, 1, 1, 1, 0, 1, 1, 0, 1],
        [0, 1, 0, 1, 0, 0, 0, 1, 0, 0],
        [1, 0, 1, 0, 1, 0, 0, 1, 1, 0],
        [1, 0, 0, 0, 1, 0, 0, 1, 0, 1],
        [0, 1, 0, 1, 1, 0, 1, 1, 0, 0],
        [1, 1, 0, 1, 1, 0, 0, 1, 1, 1],
        [0, 0, 1, 0, 1, 1, 1, 0, 0, 1]
    ]

    s = (0, 0)
    d = (6, 4 )

    min_d = Shortpath(M, s, d)

    if min_d != -1:
        print("The shortest path from source to destination has length", min_d)
    else:
        print("Destination cannot be reached from source")
