# 스택 - 원 영역 (백준 플래4)
# 문제 링크: https://www.acmicpc.net/problem/10000

# [[-][[-]-]]
'''
[[-][[-]-]]

4
7 5
-9 11
11 9
0 20

(2, 12)
(-20, 2)
(2, 20)
(-20, 20)

(-20, -20, 2, 2, 2, 12, 20, 20)
( [    [   ]  [  [   ]   ]   ]   )

'''
lines = []
N = int(input())
for i in range(N):
    x, r = map(int, input().split())
    lines.append((x-r, x+r))

# lines = [
#     (2, 12),
#     (-20, 2),
#     (2, 20),
#     (-20, 20)
# ]

# lines = [(-2, 2), (-2, 1), (1, 2)]

ls = []
for coord in lines:
    x1, x2 = coord
    ls.append((x1, '('))
    ls.append((x2, ')'))
# ls.sort()
ls = sorted(ls, key=lambda x: (x[0], '(' if x[1] == ')' else ')'))

stack = []
ans = 0
for item in ls:
    x, c = item
    if c == ')':
        # if stack's top is number
        n = None
        if stack and type(stack[-1]) is int:
            n = stack.pop()
            top = stack.pop()
            diff = x - top[0]
            if n == diff:
                ans += 2
            else:
                ans += 1
            while stack and type(stack[-1]) is int:
                diff += stack[-1]
                stack.pop()
            stack.append(diff)
        else:
            top = stack.pop()
            diff = x - top[0]
            while stack and type(stack[-1]) is int:
                diff += stack[-1]
                stack.pop()
            stack.append(diff)
            ans += 1
            pass
    else:
        stack.append(item)
    pass
print(ans + 1)