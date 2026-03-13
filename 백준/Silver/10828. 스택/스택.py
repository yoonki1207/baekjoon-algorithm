# 스택 - 스택 (백준 실버 4)
# 문제 링크: https://www.acmicpc.net/problem/10828


class Node:
    prev = None
    val = None
    def __init__(self, x, prev=None):
        self.val = x
        self.prev = prev
class Stack:
    top = Node(None)
    cnt = 0
    def push(self, x):
        self.cnt += 1
        self.top = Node(x, self.top)
        return self.top
    
    def pop(self):
        if self.empty(): return -1
        ret = self.top.val
        self.top = self.top.prev
        self.cnt -= 1
        return ret

    def size(self):
        return self.cnt
    
    def empty(self):
        if self.top.val == None: return True
        return False

N = int(input())
stk = Stack()
for i in range(N):
    line = input().split()
    cmd = line[0]
    if cmd == 'push':
        stk.push(int(line[1]))
    elif cmd == 'pop':
        ret = stk.pop()
        print(ret)
    elif cmd == 'size':
        print(stk.size())
    elif cmd == 'empty':
        if stk.empty():
            print(1)
        else:
            print(0)
    elif cmd == 'top':
        if stk.empty():
            print(-1)
        else:
            print(stk.top.val)