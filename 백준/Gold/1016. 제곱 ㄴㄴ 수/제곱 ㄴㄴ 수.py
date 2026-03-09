# 정수론 - 제곱 ㄴㄴ 수 (백준 골드1)
# 문제 링크: https://www.acmicpc.net/problem/1016

a, b = map(int, input().split())
p = 2
min_q = p*p
arr = [False] * (b - a + 2)
ans = b - a + 1
while p*p <= b:
    n = a // (p*p)
    if a % (p*p) != 0: n += 1
    while n * p * p <= b:
        if not arr[n * p * p - a]:
            arr[n * p * p - a] = True
            ans -= 1
        n += 1
    p += 1
    pass

print(ans)