# 스택 - 탑 (백준 골드5)
# 문제 링크: https://www.acmicpc.net/problem/2493

N = int(input())
arr = list(map(int, input().split()))
ans = [0 for _ in range(N)]

stk = []
for i in range(N-1, -1, -1):
    if not stk:
        stk.append((arr[i], i))
    else:
        while stk and stk[-1][0] < arr[i]:
            v, j = stk.pop()
            ans[j] = i + 1
        stk.append((arr[i], i))
print(' '.join(map(str,ans)))