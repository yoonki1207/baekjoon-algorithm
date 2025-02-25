h = []
c = []

for i in range(3):
  h.append(int(input()))
for i in range(2):
  c.append(int(input()))
ans = 1000000

for i in h:
  for j in c:
    ans = min(ans, i+j-50)

print(ans)

