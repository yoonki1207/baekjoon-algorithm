# DP - 외판원 순회 (백준 골드1)
# 문제 링크: https://www.acmicpc.net/problem/2098

N = int(input())
# N = 16
arr = [[0] * N for _ in range(N)]
# for i in range(N):
    # for j in range(N):
        # if i != j:
            # arr[i][j] = 1
cache = [float('inf')] * (2**16) # for bitmasking

for i in range(N):
    line = list(map(int, input().split()))
    for j in range(N):
        arr[i][j] = line[j]

ans = float('inf')

# bitmasking

def dfs(prev_node, visited, cache):
    if visited == (1 << N) - 1:
        if arr[prev_node][0] == 0:
            return float('inf')
        return arr[prev_node][0]
    if cache[prev_node][visited] != -1: return cache[prev_node][visited]
    cache[prev_node][visited] = float('inf')
    # cache[prev_node][visited] = float('inf')
    for next_node in range(N):
        if arr[prev_node][next_node] == 0 or (visited & (1 << next_node)): continue
        next_dfs = dfs(next_node, visited | (1 << next_node), cache) + arr[prev_node][next_node]
        cache[prev_node][visited] = min(
            cache[prev_node][visited], 
            next_dfs
        )
    return cache[prev_node][visited]
# print(dfs(0, 0, 1, [[0] * (2**16) for _ in range(16)]))
print(dfs(0, 1 ,[[-1] * (2**16) for _ in range(N)]))