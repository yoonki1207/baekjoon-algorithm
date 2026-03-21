# 위상정렬 - 작업 (백준 골드4)
# 문제 링크: https://www.acmicpc.net/problem/2056

N = int(input())
post_tasks = {}
pre_tasks = {}
for i in range(1, N + 1): 
    post_tasks[i] = []
    pre_tasks[i] = []
times = [0 for _ in range(N + 1)]
degree = [0 for _ in range(N + 1)]
for i in range(1, N + 1):
    line = list(map(int, input().split()))
    time = line[0]
    pre_task_n = line[1]
    times[i] = time
    for j in range(pre_task_n):
        pre_tasks[i].append(line[j + 2])
        post_tasks[line[j + 2]].append(i)
        degree[i] += 1

from collections import deque
visited = [False for _ in range(N + 1)]

ans = 0
q = deque()

for i in range(1, N + 1):
    if degree[i] == 0:
        q.append(i)

cost = [0] * (N + 1)
while q:
    curr_task = q.popleft()
    curr_cost = 0
    for pre_task in pre_tasks[curr_task]:
        curr_cost = max(curr_cost, cost[pre_task])
    cost[curr_task] = curr_cost + times[curr_task]

    for next_task in post_tasks[curr_task]:
        degree[next_task] -= 1
        if degree[next_task] == 0:
            q.append(next_task)


ans = max(cost)

print(ans)