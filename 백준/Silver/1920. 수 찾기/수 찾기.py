# 이분탐색 - 수 찾기 (백준 실버4)
# 문제 링크: https://www.acmicpc.net/problem/1920

def binary_search(arr, val):
    left = 0
    right = len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if val < arr[mid]:
            right = mid - 1
        elif val > arr[mid]:
            left = mid + 1
        else:
            return True
    return False

N = int(input())
line = list(map(int, input().split()))
arr = [0] * N
for i in range(N):
    arr[i] = line[i]

arr.sort()

M = int(input())
line = list(map(int, input().split()))
for val in line:
    if binary_search(arr, val):
        print(1)
    else:
        print(0)