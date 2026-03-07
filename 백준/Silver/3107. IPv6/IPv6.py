# 문자열 - IPv6 (백준 실버1)
# 문제 링크: https://www.acmicpc.net/problem/3107

ipv6 = input()
lines = ipv6.split(':')
if lines[0] == '':
    lines = lines[1:]
elif lines[-1] == '':
    lines = lines[:-1]
lines = ':'.join([line.zfill(4) if line != '' else ':'.join(['0000']*(8-len(lines)+1)) for line in lines])
print(lines)