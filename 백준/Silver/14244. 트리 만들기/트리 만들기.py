# 트리 - 트리 만들기 (백준 실버4)
# 문제 링크: https://www.acmicpc.net/problem/14244

N, M = map(int, input().split())

print(0, 1)
prev_node = 1
next_node = 2
while N - 2:
    N -= 1

    print(prev_node, next_node)
    if M > 2:
        M -= 1
        next_node += 1
    else:
        prev_node = next_node
        next_node = prev_node + 1
