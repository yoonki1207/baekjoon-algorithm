N, M = map(int, input().split())
dp = [0] * (N + 1)
for i in range(M):
    x = int(input())
    dp[x] = -1

from collections import deque

q = deque([(1, 0, 0)])
visited = [[False] * (201) for _ in range(N + 1)]
visited[1][0] = True

flag = -1
while q and flag == -1:
    pos, before, cnt = q.popleft()
    
    for offset in [-1, 0, 1]:
        after = max(1, before + offset)
        if pos + after <= N and not visited[pos + after][after] and dp[pos + after] != -1:
            visited[pos + after][after] = True
            q.append((pos + after, after, cnt + 1))
            if pos + after == N:
                flag = cnt + 1
print(flag)
