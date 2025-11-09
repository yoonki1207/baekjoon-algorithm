t = int(input())
for _ in range(t):
    s = input().split()
    n = float(s[0])
    for i in s[1:]:
        if i == '@':
            n*=3
        elif i == '%':
            n+=5
        else:
            n-=7
    print("{0:.2f}".format(n))