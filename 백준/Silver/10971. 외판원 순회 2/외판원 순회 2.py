# 백트래킹 - 외판원 순회 2 (백준 실버2)
# 문제 링크: https://www.acmicpc.net/problem/10971
N = int(input())
matrix = [[0 for _ in range(N)] for _ in range(N)]
for i in range(N):
    line = list(map(int, input().split()))
    for j in range(N):
        matrix[i][j] = line[j]

visited = [False] * N

ans = 987654321
start_node = 0
def solve(curr_node, weight):
    global ans
    for i in range(N):
        distance = matrix[curr_node][i]
        if visited[i]:
            continue
        elif distance > 0:
            visited[i] = True
            solve(i, weight + distance)
            visited[i] = False
    
    # if visit all city and can go curr_node to start_node
    if (False not in visited) and matrix[curr_node][start_node] > 0:
        ans = min(ans, weight + matrix[curr_node][start_node])
        return

for i in range(1):
    start_node = 0
    visited[start_node] = True
    solve(i, 0)
    visited[start_node] = False
print(ans)
