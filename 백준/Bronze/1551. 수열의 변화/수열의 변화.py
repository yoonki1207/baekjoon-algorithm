# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.
# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.
n, k = input().split()
n, k = int(n), int(k)
s = input().split(',')
for i in range(len(s)):
    s[i] = int(s[i])

for _ in range(k):
    for i in range(len(s)-1):
        s[i] = s[i+1] - s[i]
if k != 0:
    s = s[:-k]
s = [str(v) for v in s]
print(','.join(s))