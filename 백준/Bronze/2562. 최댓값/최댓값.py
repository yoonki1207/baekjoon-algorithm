# 파이썬 문법 - 최댓값 (백준 브론즈3)
# 문제 링크: https://www.acmicpc.net/problem/2562

arr = [0]*9
for i in range(9):
    arr[i] = int(input())
m = max(arr)
ans = 0
for i in range(9):
    if arr[i] == m:
        ans = i
print(m)
print(ans + 1)