# 분할정복 - 색종이 만들기 (백준 실버2)
# 문제 링크: https://www.acmicpc.net/problem/2630

BLUE = 1
WHITE = 0

N = int(input())
arr = [[0 for _ in range(N)] for _ in range(N)]
for i in range(N):
    line = list(map(int, input().split()))
    for j in range(N):
        arr[i][j] = line[j]


def checkAll(y: int, x: int, n: int, color: int):
    for i in range(y, y + n):
        for j in range(x, x + n):
            if arr[i][j] != color:
                return False
    return True

colorcnt = [0, 0]

def solve(y, x, n):
    allBlue = checkAll(y, x, n, BLUE)
    allWhite = checkAll(y, x, n, WHITE)
    if allBlue:
        colorcnt[BLUE] += 1
    elif allWhite:
        colorcnt[WHITE] += 1
    else:
        m = n//2
        solve(y, x, m)
        solve(y+m, x, m)
        solve(y, x+m, m)
        solve(y+m, x+m, m)
solve(0, 0, N)
for i in colorcnt:
    print(i)
