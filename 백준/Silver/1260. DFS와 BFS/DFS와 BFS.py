# 그래프, DFS, BFS - DFS와 BFS (백준 실버2)
# 문제 링크: https://www.acmicpc.net/problem/1260
from collections import deque

N, M, V = map(int, input().split())
arr = [[False for _ in range(N + 1)] for _ in range(N + 1)]
for i in range(M):
    u, v = map(int, input().split())
    arr[u][v] = arr[v][u] = True

visited = [False] * (N + 1)
visited[V] = True
result_dfs = []
def dfs(node):
    result_dfs.append(node)
    for i in range(N + 1):
        if arr[node][i] and not visited[i]:
            visited[i] = True
            dfs(i)

result_bfs = []
def bfs(node):
    visited = [False] * (N + 1)
    q = deque([node])
    visited[node] = True
    result_bfs.append(node)
    while q:
        n = q.popleft()
        for i in range(N + 1):
            if arr[n][i] and not visited[i]:
                result_bfs.append(i)
                visited[i] = True
                q.append(i)
dfs(V)
bfs(V)
result_dfs = list(map(str, result_dfs))
result_bfs = list(map(str, result_bfs))
print(' '.join(result_dfs))
print(' '.join(result_bfs))
