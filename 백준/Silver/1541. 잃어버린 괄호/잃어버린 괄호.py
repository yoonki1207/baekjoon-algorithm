# 그리디 - 잃어버린 괄호 (백준 실버2)
# 문제 링크: https://www.acmicpc.net/problem/1541

s = input()

i = 0
v = []
for j in range(len(s)):
    if s[j] == '+' or s[j] == '-':
        v.append(s[i:j])
        v.append(s[j])
        i = j + 1
v.append(s[i:])
p = False
for i in range(len(v)):
    if v[i] == '-':
        p = True
    if v[i] == '+' and p:
        v[i] = '-'
result = int(v[0])
i = 1
while i < len(v):
    if v[i] == '+':
        result += int(v[i+1])
    else:
        result -= int(v[i+1])
    i += 2
print(result)