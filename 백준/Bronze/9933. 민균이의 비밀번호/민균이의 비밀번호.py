# 해시 테이블 - 민균이의 비밀번호 (백준 브론즈1)
# 문제 링크: https://www.acmicpc.net/problem/9933

N = int(input())
arr = [0 for _ in range(N)]
s = set()
for i in range(N):
    arr[i] = input()
    s.add(arr[i])

for pwd in arr:
    rev = ''.join(reversed(pwd))
    if rev in s:
        l = len(pwd)
        m = pwd[l//2]
        print(l, m)
        break