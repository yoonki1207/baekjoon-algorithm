# 정수론 - 소수 찾기 (백준 브론즈2)
# 문제 링크: https://www.acmicpc.net/problem/1978
import math
n = int(input())
arr = map(int, input().split())

def isPrime(x):
    if x < 2: return False
    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0: 
            return False
        pass
    return True    

primes = [x for x in arr if isPrime(x)]
print(len(primes))