N = int(input())
M = int(input())
arr = [[False for _ in range(N + 1)] for _ in range(N + 1)]
for i in range(M):
    a, b = map(int, input().split())
    arr[a][b] = arr[b][a] = True

visited = [False for _ in range(N + 1)]

from collections import deque
q = deque([1])
visited[1] = True
cnt = 0

while q:
    front = q.popleft()
    cnt += 1
    for index, isCon in enumerate(arr[front]):
        if isCon and not visited[index]:
            visited[index] = True
            q.append(index)

print (cnt - 1)