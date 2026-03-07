# 문자열 - 단어 공부 (백준 브론즈1)
# 문제 링크: https://www.acmicpc.net/problem/1157

s = input().lower()
cnt = {}
alphabet = 'abcdefghijklmnopqrstuvwxyz'
for i in alphabet:
    cnt[i] = 0
for i in s:
    cnt[i] += 1
m = 0
k = 'a'
for key in cnt:
    if cnt[key] > m: 
        m = cnt[key]
        k = key
w = 0
for key in cnt:
    if cnt[key] == m: w += 1

if w > 1:
    print('?')
else :
    print(k.upper())
