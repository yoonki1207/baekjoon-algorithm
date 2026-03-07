# 정수론 - 골드바흐의 추측 (백준 실버2)
# 문제 링크: https://www.acmicpc.net/problem/9020
def goldbach(n):
    h = n//2
    while h > 1:
        while not prime[h]: h -=1
        r = n - h
        if prime[r]:
            return (h, r)
        h -= 1
    return (0, 0)

prime = [True] * 10001
prime[1] = False
for n in range(2, 10001):
    if prime[n]:
        j = n*2
        while j < 10001:
            prime[j] = False
            j += n

N = int(input())
for i in range(N):
    n = int(input())
    a, b = goldbach(n)
    print(a, b)