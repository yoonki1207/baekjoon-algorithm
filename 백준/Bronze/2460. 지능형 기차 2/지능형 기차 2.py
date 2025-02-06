
# Online Python - IDE, Editor, Compiler, Interpreter
w = 0
ans = 0
for i in range(10):
    a, b = map(int, input().split())
    w -= a
    w += b
    ans = max(ans, w)
print(ans)
