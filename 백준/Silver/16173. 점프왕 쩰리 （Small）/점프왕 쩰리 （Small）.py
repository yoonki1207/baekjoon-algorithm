# 그래프, DFS, BFS - 점프왕 쩰리 (백준 실버4)
# 문제 링크: https://www.acmicpc.net/problem/16173

N = int(input()) # input
jump_power = [[0 for _ in range(N)] for _ in range(N)]
visited = [[False for _ in range(N)] for _ in range(N)]
for i in range(N):
    line = list(map(int, input().split())) # input
    for j in range(N):
        jump_power[i][j] = line[j]
        if line[j] == 0: visited[False]

from collections import deque


q = deque([(0, 0)])
visited[0][0] = True

finished = False
while q and not finished:
    y, x = q.popleft()
    # print(y, x)
    if y == N - 1 and x == N - 1: finished = True
    p = jump_power[y][x]
    if p == 0: continue
    if y + p < N and not visited[y+p][x]:
        visited[y+p][x]
        q.append((y + p, x))
    if x + p < N and not visited[y][x+p]:
        visited[y][x+p]
        q.append((y, x + p))

if finished:
    print("HaruHaru")
else:
    print("Hing")