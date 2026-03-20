# 그래프, DFS, BFS - 연결 요소의 개수 (백준 실버2)
# 문제 링크: https://www.acmicpc.net/problem/11724

N, M = map(int, input().split())
arr = [[False for _ in range(N + 1)] for _ in range(N + 1)]
visited = [False for _ in range(N + 1)]
for i in range(M):
    u, v = map(int, input().split())
    arr[u][v] = arr[v][u] = True

from collections import deque

cnt = 0
for v in range(1, N + 1):
    if visited[v]: continue
    visited[v] = True
    q = deque([v])
    cnt += 1
    while q:
        node = q.popleft()
        for i in range(1, N + 1):
            if arr[node][i] and not visited[i]:
                visited[i] = True
                q.append(i)
print(cnt)