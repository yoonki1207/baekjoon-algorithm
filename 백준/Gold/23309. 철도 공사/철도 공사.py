# 링크드리스트 - 철도 공사 (백준 골드4)
# 문제 링크: https://www.acmicpc.net/problem/23309
import sys
input = sys.stdin.readline

MAX_N = 1000001

N, M = map(int, input().split())
line = list(map(int, input().split()))

next = [-1 for _ in range(MAX_N)]
prev = [-1 for _ in range(MAX_N)]

for i in range(len(line) - 1):
    next[line[i]] = line[i+1]
    prev[line[i]] = line[i-1]
next[line[-1]] = line[0]
if len(line) > 1:
    prev[line[-1]] = line[-2]
else:
    prev[line[-1]] = line[0]

def printline(station, next):
    fin = station
    print(station, end=' ')
    station = next[station]
    while station != fin:
        print(station, end=' ')
        station = next[station]
    print()

def pushRight(i, j):
    next_station = next[i]
    next[i] = j
    prev[next_station] = j
    next[j] = next_station
    prev[j] = i
    return next_station

def pushLeft(i, j):
    prev_station = prev[i]
    prev[i] = j
    next[prev_station] = j
    prev[j] = prev_station
    next[j] = i
    return prev_station

def popRight(i):
    del_station = next[i]
    next_station = next[del_station]
    next[i] = next_station
    prev[next_station] = i
    next[del_station] = prev[del_station] = -1
    return del_station

def popLeft(i):
    del_station = prev[i]
    prev_station = prev[del_station]
    prev[i] = prev_station
    next[prev_station] = i
    next[del_station] = prev[del_station] = -1
    return del_station

output = [0 for _ in range(M)]
j = 0

for i in range(M):
    line = input().split()
    cmd = line[0]
    if cmd == 'BN':
        result = pushRight(int(line[1]), int(line[2]))
        pass
    if cmd == 'BP':
        result = pushLeft(int(line[1]), int(line[2]))
        pass
    if cmd == 'CN':
        result = popRight(int(line[1]))
        pass
    if cmd == 'CP':
        result = popLeft(int(line[1]))
        pass
    output[j] = result
    j += 1

ans = '\n'.join(map(str, output))
print(ans)

