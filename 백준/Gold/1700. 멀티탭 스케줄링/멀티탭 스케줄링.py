# 그리디 - 멀티탭 스케줄링 (백준 골드1)
# 문제 링크: https://www.acmicpc.net/problem/1700
import sys
input = sys.stdin.readline

N, K = map(int, input().split())
line = list(map(int, input().split()))
cnt_left = [0] * (K + 1)
pos = [0] * (K + 1)
arr = [0] * N
ans = 0
for i in range(len(line)):
    pos[line[i]] = -i
    cnt_left[line[i]] += 1

for i in range(K):
    flag = False
    x = line[i]
    for j in range(N):
        if arr[j] == 0: # empty
            arr[j] = x
            flag = True
            break
        elif x == arr[j]: # not empty, already in
            flag = True
            break
    if flag: continue

    pos = []
    for j in range(N):
        # 가장 처음 등장하는 arr[j]의 위치.
        # arr[j]들 중 가장 나중에 등장하는 arr[j]의 인덱스 j
        t = (9999, j)
        for k in range(i + 1, K):
            if arr[j] == line[k]:
                t = (k, j)
                break
            pass
        pos.append(t)
        pass
    pos.sort(reverse=True)
    if not pos:
        idx = 0
    else:
        idx = pos[0][1]
    arr[idx] = x
    ans += 1
print(ans)
