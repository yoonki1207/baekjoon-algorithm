# 재귀함수 - 하노이 탑 (백준 골드5)
# 문제 링크: https://www.acmicpc.net/problem/1914

'''
1번 탑을 3번 탑에 올리려면,
맨 마지막 장을 제외한 나머지 탑을 2번 자리에 옮기고
1번 탑을 3번 자리에 옮긴 후
2번탑을 3번 탑에 올려야한다.
'''
N = int(input())
cnt = 0
def hinoi(n, a, b, c):
    global cnt
    if n == 1:
        print(a, b)
        cnt += 1
        return
    hinoi(n-1, a, c, b)
    print(a, b)
    cnt += 1
    hinoi(n-1, c, b, a)

def fordp(n):
    arr = [0]*(n+1)
    arr[1] = 1
    for i in range(2, n+1):
        arr[i] = arr[i-1]*2 + 1
    return arr[n]
if N <= 20:
    print(fordp(N))
    hinoi(N, 1, 3, 2)
else:
    print(fordp(N))