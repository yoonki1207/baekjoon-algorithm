# 링크드리스트 - 에디터 (백준 실버2)
# 문제 링크: https://www.acmicpc.net/problem/1406

class Node:
    val = ''
    prev = None
    next = None

    def push(self, val):
        node = Node()
        node.val = val
        nextNode = self.next
        self.next = node
        node.prev = self
        if nextNode:
            nextNode.prev = node
            node.next = nextNode
        return node
    
    def delete(self):
        if self.prev == None: return self
        prev = self.prev
        next = self.next
        prev.next = next
        if next:
            next.prev = prev
        return prev
    
    def left(self):
        if self.prev == None: return self
        return self.prev
    
    def right(self):
        if self.next == None: return self
        return self.next

s = input()
T = int(input())
cursor = Node()
for c in s:
    cursor = cursor.push(c)
for i in range(T):
    line = input()
    if len(line) >= 2:
        line = line.split()
        # P x
        cursor = cursor.push(line[1])
        pass
    else:
        if line == 'L':
            # left
            cursor = cursor.left()
            pass
        elif line == 'D':
            #right
            cursor = cursor.right()
            pass
        elif line == 'B':
            # delete a char 
            cursor = cursor.delete()
            pass
while cursor.prev != None:
    cursor = cursor.prev

printList = []
while cursor != None:
    printList.append(cursor.val)
    cursor = cursor.next
print(''.join(printList))