# 백트래킹 - 비숍 (백준 플래5)
# 문제 링크: https://www.acmicpc.net/problem/1799

N = int(input())
board = [[0 for _ in range(N)] for _ in range(N)]
left = [False] * (2*N)
right = [False] * (2*N)

for i in range(N):
    line = list(map(int, input().split()))
    for j in range(N):
        board[i][j] = line[j]

def placeable(y, x):
    return not (right[y+x] or left[y-x])

ans = 0

# coords = [(0, 0) for _ in range(N * N)]
coords = []
y, x = 0, 0
i = 0
gfp = [(0, 0) for _ in range(N)]
coord = []
while len(coords) < N:
    coord.append((y, x))
    if y == 0:
        coords.append(coord)
        coord = []
    x += 1
    y -=1
    if y < 0:
        y = x
        x = 0
    i += 1
y = N-1
k = 1
x = k
l = len(coords) - 1
# print(coords)
while len(coords) < N*2-1:
    coord = []
    for i in range(l):
        coord.append((y, x))
        y -= 1
        x += 1
    l -= 1
    y = N-1
    k += 1
    x = k
    coords.append(coord)

# print(coords)
# print([len(coord) for coord in coords])

ans = 0
def solve(position, n):
    global ans
    if position >= len(coords):
        ans = max(ans, n)
        return
    for y, x in coords[position]:
        if placeable(y, x) and board[y][x] == 1:
            left[y-x] = right[y+x] = True
            solve(position + 2, n + 1)
            left[y-x] = right[y+x] = False
    solve(position + 2, n)
    

solve(0, 0)
a = ans
ans = 0
solve(1, 0)
b = ans
print(a + b)