N = int(input())
meetings = []
for i in range(N):
    s, e = map(int, input().split())
    meetings.append((s, e))
meetings.sort(key=lambda x: (x[1], x[0]))
stk = [meetings[0]]
for s, e in meetings[1:]:
    if stk[-1][1] <= s:
        stk.append((s, e))
print(len(stk))