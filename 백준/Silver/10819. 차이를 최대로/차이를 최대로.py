# 완전탐색 - 차이를 최대로 (백준 실버2)
# 문제 링크: https://www.acmicpc.net/problem/10819

# permutation
n = int(input())
line = list(map(int, input().split()))

visited = [False] * n

stk = []
ans = 0
def dfs():
    global stk
    if len(stk) == n:
        result = 0
        for i in range(1, n):
            result += abs(line[stk[i]] - line[stk[i-1]])
        global ans
        ans = max(ans, result)
        return
    for i in range(n):
        if not visited[i]:
            visited[i] = True
            stk.append(i)
            dfs()
            stk.pop()
            visited[i] = False
for i in range(n):
    visited[i] = True
    stk.append(i)
    dfs()
    stk.pop()
    visited[i] = False
print(ans)