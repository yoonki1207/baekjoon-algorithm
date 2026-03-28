import sys
input = sys.stdin.readline
T = int(input())
while T:
    T -= 1
    N = int(input())
    coins = list(map(int, input().split()))
    M = int(input())
    # i원을 만드는 경우의 수 = dp[i]
    # dp[i] = dp[i-coin[0]]
    dp = [[0]*(M + 1) for _ in range(N + 1)]
    coins.sort()
    dp[0][0] = 1
    for i in range(M + 1):
        if i % coins[0] == 0:
            dp[0][i] = 1
    for i in range(1, len(coins)):
        for j in range(M + 1):
            dp[i][j] = dp[i-1][j]
            if j - coins[i] >= 0:
                dp[i][j] += dp[i][j-coins[i]]
    print(dp[N-1][M])
