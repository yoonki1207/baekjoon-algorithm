# 트리 - 이진 검색 트리 (백준 골드4)
# 문제 링크: https://www.acmicpc.net/problem/5639
import sys
sys.setrecursionlimit(10**5 + 1)

lines = list()

for line in sys.stdin:
    lines.append(int(line))


def post_to_pre(arr, start, end):
    if start > end: return []
    if start == end: return [arr[start]]
    root = arr[start]
    i = start + 1
    while i <= end and arr[i] < root:
        i += 1
    left_order = post_to_pre(arr, start + 1, i - 1)
    right_order = post_to_pre(arr, i, end)
    return left_order + right_order + [root]
output_line = '\n'.join(map(str, post_to_pre(lines, 0, len(lines) - 1)))
print(output_line)