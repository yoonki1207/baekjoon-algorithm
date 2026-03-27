# 그리디 - 신입 사원 (백준 실버1)
# 문제 링크: https://www.acmicpc.net/problem/1946

T = int(input())

while T:
    T -= 1
    N = int(input())
    v = [0] * N
    for i in range(N):
        a, b = map(int, input().split())
        v[i] = (a, b)
    v.sort() # [(1, 4), (2, 3), (3, 2), (4, 1), (5, 5)]
    x = v[0][1]
    cnt = 1
    for i in v:
        if x > i[1]:
            x = i[1]
            cnt += 1
    print(cnt)