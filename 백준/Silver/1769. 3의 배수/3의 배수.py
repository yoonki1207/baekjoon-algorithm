n = input()

ans = 0
if len(n) > 3:
    ans += 1
    tmp = 0
    for i in n:
        tmp += int(i)
    n = tmp
else:
    n = int(n)
while n >= 10:
    tmp = 0
    while n > 0:
        tmp += n%10
        n = n // 10
    n = tmp
    ans += 1
    
print(ans)
if n % 3 == 0:
    print("YES")
else:
    print("NO")
