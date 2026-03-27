# 그리디 - 동전 0 (백준 실버4)
# 문제 링크: https://www.acmicpc.net/problem/11047

N, K = map(int, input().split())
coins = [0]*N
for i in range(N):
    coins[i] = int(input())

coins.sort(reverse=True)

cnt = 0
for coin in coins:
    if K >= coin:
        n = K // coin
        cnt += n
        K -= n * coin
print(cnt)