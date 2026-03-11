a, b, c = map(int, input().split())
eq = '=='
ops = '*+-/'

ans = ''
for i in ops:
    if ans != '': break
    s = str(a)+eq+str(b)+i+str(c)
    s = "k="+s
    exec(s)
    if k:
        ans = s
for i in ops:
    if ans != '': break
    s = str(a)+i+str(b)+eq+str(c)
    s = "k="+s
    exec(s)
    if k:
        ans = s
print(ans[2:].replace('==', '='))
