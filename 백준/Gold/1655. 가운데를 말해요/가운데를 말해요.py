# 큐 - 가운데를 말해요 (백준 골드2)
# 문제 링크: https://www.acmicpc.net/problem/1655
import sys
input = sys.stdin.readline

MAX_LEN = 20001
tree = [0] * MAX_LEN * 4

def update(start, end, n, pos, diff):
    if start > pos or end < pos: return 
    tree[n] += 1
    if start == end: return
    mid = (start + end) // 2
    update(start, mid, n*2, pos, diff)
    update(mid + 1, end, n*2+1, pos, diff)

def query(start, end, n, pos): # pos start from 1.
    if start > end:
        return None
    if start == end: return start
    left_sum = tree[n*2]
    mid = (start + end) // 2
    if left_sum >= pos:
        return query(start, mid, n*2, pos)
    else:
        return query(mid+1, end, n*2+1, pos - left_sum)
    # right_sum = tree[n*2+1] 
    pass

N = int(input())
OFFSET = 10000
for i in range(N):
    x = int(input())
    x = x + OFFSET
    update(0, MAX_LEN, 1, x, 1)
    pos = i // 2 + 1
    if i % 2 == 1: # 짝수번째 입력일 때
        result1 = query(0, MAX_LEN, 1, pos)
        result2 = query(0, MAX_LEN, 1, pos + 1)
        result = min(result1, result2)
    else :
        result = query(0, MAX_LEN, 1, pos)
    print(result - OFFSET)
    pass
