# DFS - 이분 그래프 (백준 골드4)
# 문제 링크: https://www.acmicpc.net/problem/1707

from collections import deque

K = int(input())

while K:
    ans = True
    K -= 1
    V, E = map(int, input().split())
    # A의 이웃은 B이므로, 모든 노드를 순회하며 B의 이웃이 B일 수 있는지 모순을 이용한다.
    # arr = [i for i in range(1, )
    color = [None] * (V + 1)
    visited = [False] * (V + 1)
    adj = {}
    for i in range(1, V + 1): adj[i] = []
    for i in range(E):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)
    visited = [False] * (V + 1)
    for i in range(1, V + 1): # i로 시작하는
        if visited[i]: continue
        q = deque([i])
        visited[i] = True
        color[i] = 'R'
        while q:
            node = q.popleft()
            c = color[node]
            rc = ('R' if c == 'B' else 'B')
            for j in adj[node]: # 인접한 노드들
                if not color[j]: # 이웃에 색이 없으면
                    color[j] = rc # 입혀준다.
                    visited[j] = True
                    q.append(j)
                elif color[j] == c: # 이웃에 색이 있으나 같다면
                    ans = False # 답을 False로 바꾸고 break한다.
                    break
    ans = ('YES' if ans else 'NO')
    print(ans)