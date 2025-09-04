n, m = input().split()
n, m = int(n), int(m)

res = True
i = 2
while i < m:
  if n % i == 0: 
    res = False
    break
  i+=1

if res == True:
  print("GOOD")
else:
  print("BAD "+str(i))