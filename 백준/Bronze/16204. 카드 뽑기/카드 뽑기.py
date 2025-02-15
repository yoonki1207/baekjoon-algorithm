m, n, k = map(int, input().split())
print(min(n, k)+min(m-n,m-k))