# 링크드리스트 - malloc (백준 골드1)
# 문제 링크: https://www.acmicpc.net/problem/3217
import sys
input = sys.stdin.readline

def getParam(s, type=None):
    # ret = s.split('(')[1].split(')')[0] # system readline으로 인한 추가 문자 삭제
    ret = s[s.find('(')+1:s.find(')')]
    if type: return type(ret)
    return ret

N = int(input())

# allocatable_address = [0]
loaded_variables = {'?': (0, 0), '!': (100001, 100002)}
class Var:
    name = None
    next = None
    prev = None
    left = 0
    right = 0

head = Var()
tail = Var()
head.name = '_'
head.next = tail
tail.prev = head
tail.left = 100001
tail.right = 100100
trash = {}

def loadVariable(var):
    if var in loaded_variables:
        loaded_variables.pop(var)
    loaded_variables[var] = Var()
    loaded_variables[var].name = var
    return loaded_variables[var]

def pushNext(curr, node): # push node next to curr
    # 항상 curr node는 마지막 노드가 아니라고 가정
    next = curr.next
    curr.next = node
    node.prev = curr
    node.next = next
    next.prev = node

def allocateMemory(node, left, right):
    node.left = left
    node.right = right

def canLoad(size, var):
    curr = head
    node = loadVariable(var)
    while curr.next: # next가 존재한다면
        next = curr.next
        # print(curr.name, next.left, curr.right)
        if next.left - curr.right - 1 >= size: # next의 left 와 curr의 right로 메모리 할당 가능 여부 확인
            # Allocate memory
            pushNext(curr, node)
            allocateMemory(node, curr.right + 1, curr.right + size)
            return
        else:
            curr = curr.next
        
def free(var):
    if var in loaded_variables:
        # loaded_variables[var].left = loaded_variables[var].right = 0
        deleted_node = loaded_variables.pop(var)
        if deleted_node.prev and deleted_node.next:
            deleted_node.prev.next = deleted_node.next
            deleted_node.next.prev = deleted_node.prev
    pass

tmp_n = 0
for i in range(N):
    line = input()
    if '=' in line: # aabb=malloc(50001);
        line = line.split('=')
        var = line[0]
        size = getParam(line[1], int)
        canLoad(size, var)

    elif line[0] == 'f': # free
        free(getParam(line))

    else: # print
        var = getParam(line)
        if var not in loaded_variables:
            print(0)
        else:
            print(loaded_variables[var].left)

# print(loaded_variables)

# curr = head
# print("___")
# while curr.name:
#     print(curr.name)
#     curr = curr.next

'''
5
kaka=malloc(100000);
print(kaka);
free(kaka);
kaka=malloc(100);
print(kaka);

1
1

Runtime Error: key error
key error not work

4
kaka=malloc(90900);
print(kaka);
kaka=malloc(100);
print(kaka);

90901

4
kaka=malloc(99900);
print(kaka);
kaka=malloc(100);
print(kaka);
1
99901


10
kaka=malloc(10000);
mama=malloc(10000);
papa=malloc(10000);
tata=malloc(10000);
free(mama);
free(tata);
qaqa=malloc(5001);
papa=malloc(5001);
print(qaqa);
print(papa);

10001
30001


'''