# 트리 - 트리의 부모 찾기 (백준 실버2)
# 문제 링크: https://www.acmicpc.net/problem/11725
import sys
sys.setrecursionlimit(10**5 + 1)

N = int(input())
visited = [False] * (N + 1)
graph = {}
for i in range(1, N + 1): graph[i] = []
for i in range(N - 1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
# print(graph)

parent = [0] * (N + 1)

def dfs(node):
    for next_node in graph[node]:
        if not visited[next_node]:
            visited[next_node] = True
            if parent[next_node] == 0:
                parent[next_node] = node
            dfs(next_node)
dfs(1)
output = '\n'.join(map(str, parent[2:]))
print(output)