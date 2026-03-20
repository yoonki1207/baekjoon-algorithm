# BFS - 미로 탐색 (백준 실버1)
# 문제 링크: https://www.acmicpc.net/problem/2178

N, M = map(int, input().split())
board = [[0 for _ in range(M)] for _ in range(N)]
visited = [[False for _ in range(M)] for _ in range(N)]
for i in range(N):
    line = input()
    for j in range(M):
        board[i][j] = (1 if line[j] == '1' else 0)

from collections import deque
q = deque([(0, 0, 1)])
offset = [[-1, 0], [1, 0], [0, -1], [0, 1]]
visited[0][0] = True

while q:
    y, x, d = q.popleft()
    for offset_y, offset_x in offset:
        ny = y + offset_y
        nx = x + offset_x
        if ny >= 0 and nx >= 0 and ny < N and nx < M and board[ny][nx] == 1 and not visited[ny][nx]:
            visited[ny][nx] = True
            if ny == N - 1 and nx == M - 1:
                print(d + 1)
                exit()
            q.append((ny, nx, d + 1))
