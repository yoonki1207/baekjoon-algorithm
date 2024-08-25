n = int(input())
if n == 0: 
    n = 1
ans = 1
while n >= 1:
    ans *= n
    n -= 1
print(ans)