# BFS - 동전 2 (백준 골드5)
# 문제 링크: https://www.acmicpc.net/problem/2294

n, k = map(int, input().split())
arr = set()
for i in range(n):
    a = int(input())
    if a <= k:
        arr.add(a)
    pass
arr = list(arr)
arr.sort(reverse=True)
INF = 987654321
ans = INF

class Node(object):
    def __init__(self, index, target, used_coin):
        self.index = index
        self.target = target
        self.used_coin = used_coin

    def __lt__(self, other):
        return self.used_coin < other.used_coin
    
    def values(self):
        return (self.index, self.target, self.used_coin)


from collections import deque

visited = [-1] * (k + 1)
visited[0] = 0

q = deque([0])

while q:
    curr = q.popleft()
    
    for coin in arr:
        n = curr + coin
        if n > k:
            continue
        if visited[n] != -1:
            continue
        visited[n] = visited[curr] + 1

        if n == k:
            print(visited[n])
            exit()
        q.append(n)

# dfs(arr, 0, k, 0)
if ans == INF:
    print(-1)
else:
    print(ans)

'''
10 10000
1
2
3
4
5
6
7
8
9
10

3 15
4
6
7


'''