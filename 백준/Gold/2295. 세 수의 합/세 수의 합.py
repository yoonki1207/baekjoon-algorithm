# 해시 테이블 - 세 수의 합 (백준 골드4)
# 문제 링크: https://www.acmicpc.net/problem/2295
N = int(input())
# N = 1000000
arr = [1] * N

for i in range(N):
    arr[i] = int(input())
arr.sort()

s = set()
for i in range(N):
    for j in range(i, N):
        if arr[i] + arr[j] <= arr[-1]:
            s.add(arr[i] + arr[j])
ans = None
for i in range(N-1, -1, -1):
    for j in range(0, i):
        diff = arr[i] - arr[j]
        if diff in s:
            ans = arr[i]
            break
    if ans:
        break
print(ans)
