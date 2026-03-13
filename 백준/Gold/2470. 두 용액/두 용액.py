# 이분탐색 - 두 용액 (백준 골드5)
# 문제 링크: https://www.acmicpc.net/problem/2470

N = int(input())
line = list(map(int, input().split()))

line.sort()

def binary_search(arr, left, right, pivot):
    mid = -99
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] + pivot <= 0:
            left = mid + 1
            pass
        else:
            right = mid - 1
            pass
        update(pivot, arr[mid])
    return mid

def update(a, b):
    global ans, diff
    curr_diff = abs(a + b)
    if curr_diff < diff:
        diff = curr_diff
        ans = (a, b)

'''
Idea
오름차순으로 정렬한다.
왼쪽부터 순회하며 key값을 하나 잡는다.
upper_bound index를 찾는다.
해당 index와 index-1을 비교하여 최소차이를 갱신한다.

-7 -3 -1
7 3 1

5
-2 4 -99 -1 98


5
1 1 1 -2 1

3
-91 -92 -93

3
-1 -2 -3
'''
ans = (line[0], line[1])
diff = abs(9234567890)
for i in range(len(line)):
    # key
    index = binary_search(line, i + 1, len(line) - 1, line[i])
    pass

if ans[0] > ans[1]: ans[0], ans[1] = ans[1], ans[0]
print(ans[0], ans[1])