# 큐 - 카드2 (백준 실버4)
# 문제 링크: https://www.acmicpc.net/problem/2164

class Node:
    prev = None
    next = None
    val = None

class Queue:
    cnt = 0
    head = None
    tail = None
    def size(self):
        return self.cnt
    
    def push(self, x):
        node = Node()
        node.val = x
        if self.size() == 0:
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            node.prev = self.tail
            self.tail = node
        self.cnt += 1
    def pop(self):
        if self.size() == 0: return None
        val = self.head.val
        self.head = self.head.next
        if self.head:
            self.head.prev = None
        self.cnt -= 1
        return val

N = int(input())
q = Queue()
for i in range(1, N+1):
    q.push(i)

while q.size() > 1:
    q.pop()
    x = q.pop()
    q.push(x)

print(q.head.val)
