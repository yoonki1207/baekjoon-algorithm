# 분할정복 - 색종이 만들기 (백준 실버2)
# 문제 링크: https://www.acmicpc.net/problem/2630

N = int(input())
arr = [[0 for _ in range(N)] for _ in range(N)]
for i in range(N):
    line = list(map(int, input().split()))
    for j in range(N):
        arr[i][j] = line[j]

def isAllColor(y, x, m, color):
    for i in range(y, y + m):
        for j in range(x, x + m):
            if arr[i][j] != color:
                return False
    return True

white_cnt = 0 # white is 0
blue_cnt = 0 # blue is 1
WHITE = 0
BLUE = 1

def cutPaper(y, x, m):
    global blue_cnt, white_cnt
    if isAllColor(y, x, m, WHITE):
        white_cnt += 1
        return
    if isAllColor(y, x, m, BLUE): 
        blue_cnt += 1
        return
    m //= 2
    cutPaper(y, x, m)
    cutPaper(y+m, x, m)
    cutPaper(y, x+m, m)
    cutPaper(y+m, x+m, m)

cutPaper(0, 0, N)
print(white_cnt)
print(blue_cnt)