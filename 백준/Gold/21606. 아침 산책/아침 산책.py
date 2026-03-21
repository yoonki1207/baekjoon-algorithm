# 그래프, DFS, BFS - 아침 산책 (백준 골드3)
# 문제 링크: https://www.acmicpc.net/problem/21606
import sys
sys.setrecursionlimit(2*(10**5)+1)

N = int(input())
line_color = input()
color = [0] + [int(i) for i in line_color]
graph = {}
for i in range(1, N + 1): graph[i] = []
for i in range(N-1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
'''
어떤 실외 정점 x가 가지고 있는 값은 그 실외 정점에서 시작하여 만날 수 있는 실내 정점의 갯수
그리고 그 실외 정점이 탐색하며 만난 모든 실외 정점은 실외 정점 x의 값과 같다.

어떤 실내 정점 x의 이웃이 실외정점이라면 실외정점의 값 -1, 실내정점이라면 1을 모두 더한 값은 실내 정점 x에서 출발하여 도달할 수 있는 모든 경로의 경우의 수이다.
'''

values = [-1] * (N + 1)

from collections import deque

for start_node in range(1, N + 1): # 실외 degree 계산
    if color[start_node] == 1: continue
    visited = [False] * (N + 1)
    passed_outdoor = []
    indoor_cnt = 0
    q = deque([start_node])
    visited[start_node] = True

    if values[start_node] != -1: continue
    while q:
        curr = q.popleft()
        if color[curr] == 1:
            indoor_cnt += 1
            continue
        else:
            passed_outdoor.append(curr)
        for next in graph[curr]:
            if visited[next]: continue
            visited[next] = True
            q.append(next)
    for outdoor_node in passed_outdoor:
        values[outdoor_node] = indoor_cnt

ans = 0
for node in range(1, N+1):
    if color[node] == 0: continue
    route_cnt = 0
    for next_node in graph[node]:
        if color[next_node] == 1:
            route_cnt += 1
        else:
            route_cnt += values[next_node] - 1
    ans += route_cnt
print(ans)