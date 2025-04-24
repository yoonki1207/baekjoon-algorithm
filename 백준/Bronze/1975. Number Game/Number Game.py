t = int(input())

for i in range(t):
    n = int(input())
    ans = 1
    if n == 1: 
        ans = 0
    for j in range(2, n//2+1):
        if n%j == 0:
            m = n
            while m % j == 0:
                ans += 1
                m /= j
                
    print(ans)
    
'''
n=4
2: 100
3: 11
4: 10

1000
2 8 = 4
'''