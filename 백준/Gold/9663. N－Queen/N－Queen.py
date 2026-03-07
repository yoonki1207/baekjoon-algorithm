# 백트래킹 - N-Queen (백준 골드4)
# 문제 링크: https://www.acmicpc.net/problem/9663
N = int(input())

top = [False for _ in range(N)]
right = [False for _ in range(N * 2)]
left = [False for _ in range(N * 2)]

def isPlaceable(y, x):
    if top[x] or left[y-x] or right[x+y]:
        return False
    return True

# returns (y, x)
def getCoord(position: int):
    return (position // N, position % N)

cnt = 0
def solve(y):
    global cnt
    if y == N:
        cnt += 1
        return
    for nx in range(N):
        if isPlaceable(y, nx):
            right[y + nx] = True
            left[y - nx] = True
            top[nx] = True
            solve(y + 1)
            top[nx] = False
            left[y - nx] = False
            right[y + nx] = False
solve(0)
print(cnt)